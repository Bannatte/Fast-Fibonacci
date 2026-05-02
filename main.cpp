#include <vector>
#include <iostream>
#include <cmath>
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

int fast_fib (int num)
{
  if (num <= 0) {
    return 0;
  }

  Zsqrt5 two_power = {1, 1};
  Zsqrt5 tot_power = {1, 0};

  int temp = num;
  int i = 0;
  while (temp > 0) {
    
    int b = temp & 1;
    if (b) {
      tot_power *= two_power;
    }

    two_power *= two_power;
    temp >>= 1;
    i++;
  }

  // power = (1 + sqrt(5))^n
  // fib = power / (sqrt(5) * 2^n)
  //     = (a + bsqrt(5)) / (sqrt(5) * 2^n)
  //     = (b + a / sqrt(5)) * 2^-n
  //     = (b + a / sqrt(5)) >> n
  double sqrt5 = 2.23606797749979;
  long long fib = (long long)(power.b + power.a / sqrt5);
  fib >>= num;

  if (num % 2 == 1) {
    fib++;
  }

  return (int)fib;
}

int main()
{
  for (int k = 1; k <= 10; k++) {
    int fib = fast_fib(k);
    cout << "k: " << k << ", fib: " << fib << '\n';
  }
  return 0;
}
