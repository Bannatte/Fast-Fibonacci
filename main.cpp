#pragma GCC optimize("O3")
#include <iostream>

struct Zsqrt5 {
  long long a;
  long long b;

  Zsqrt5& operator*=(const Zsqrt5& other) {
    const long long oa = other.a;
    const long long ob = other.b;
    
    long long na = a * oa + 5 * b * ob;
    long long nb = a * ob + b * oa;

    a = na;
    b = nb;

    return *this;
  }
};

long long fast_fib (int num)
{
  if (num <= 0) {
    return 0;
  }

  Zsqrt5 two_power = {1, 1};
  Zsqrt5 tot_power = {1, 0};

  int temp = num;
  while (temp > 0) {
    
    if (temp & 1) {
      tot_power *= two_power;
    }

    two_power *= two_power;
    temp >>= 1;
  }

  static constexpr long double inv_sqrt5 = 0.4472135954999579L; // 1 / sqrt(5)
  long long fib = (long long)(tot_power.b + (long double)tot_power.a * inv_sqrt5);
  fib >>= num;

  fib += (num & 1);
  return fib;
}

int main()
{
  for (int k = 1; k <= 10; k++) {
    int fib = fast_fib(k);
    std::cout << "k: " << k << ", fib: " << fib << '\n';
  }
  return 0;
}
