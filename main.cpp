#include <vector>
#include <iostream>
using namespace std;

int div_sqrt_five (int num)
{
  int low = num / 3;
  int upp = num / 2;

  long long target = num * num;
  while (low <= upp) 
  {
    int mid = (low + upp) / 2;
    long long value = 5 * mid * mid;

    if (value == target) {
      return mid;
    } else if (value < target) {
      low = mid + 1;
    } else {
      upp = mid - 1;
    }
  }

  return upp;
}

int fast_fib (int num) {
  int highest_bit = 31;
  while (((num >> highest_bit) & 1) == 0) {
    highest_bit--;
  }

  vector<int> p = {1};
  vector<int> q = {1};

  for (int i = 0; i <= highest_bit; i++) {
    p.push_back(p[i] * p[i] + 5 * q[i] * q[i]);
    q.push_back(2 * p[i] * q[i]);
  }
  
  int p_tot = 1;
  int q_tot = 0;
  for (int j = highest_bit; 0 <= j; j--) {
    int b = (num >> j) & 1;

    if (b != 1) {
      continue;
    }

    int p_tot_new = p[j] * p_tot + q[j] * q_tot * 5;
    q_tot = q[j] * p_tot + p[j] * q_tot;
    p_tot = p_tot_new;
  }

  int fib = (div_sqrt_five(p_tot) + q_tot) >> num;

  if (num % 2 == 1) {
    fib++;
  }

  return fib;
}
