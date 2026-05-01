#include <vector>
#include <iostream>
using namespace std;

struct Zsqrt5 {
  int a;
  int b;

  Zsqrt5 operator*(const Zsqrt5& other) const {
    return {a * other.a + 5 * b * other.b, a * other.b + b * other.a};
  }

  Zsqrt5& operator*=(const Zsqrt5& other) {
    int na = a * other.a + 5 * b * other.b;
    int nb = a * other.b + b * other.a;

    a = na;
    b = nb;

    return *this;
  }
};

long long div_sqrt_five (long long num)
{
  long long low = num / 3;
  long long upp = num / 2;

  long long target = num * num;
  while (low <= upp) 
  {
    long long mid = (low + upp) / 2;
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

int fast_fib (int num)
{
  if (num <= 0) {
    return 0;
  }
  
  int highest_bit = 31;
  while (((num >> highest_bit) & 1) == 0) {
    highest_bit--;
  }

  Zsqrt5 initial = {1, 1};
  vector<Zsqrt5> list = {initial};

  for (int i = 0; i <= highest_bit; i++) {
    Zsqrt5 next = list[i] * list[i];
    list.push_back(next);
  }
  
  Zsqrt5 power = {1, 0};
  for (int j = highest_bit; 0 <= j; j--) {
    int b = (num >> j) & 1;

    if (b != 1) {
      continue;
    }

    power *= list[j];
  }

  long long fib = (div_sqrt_five(power.a) + power.b) >> num;

  if (num % 2 == 1) {
    fib++;
  }

  return (int)fib;
}

int main()
{
  for (int k = 1; k <= 10; k++) {
    int fib = fast_fib(k);
    cout << "k: " << k << ", fib: " << fib << endl;
  }
}
