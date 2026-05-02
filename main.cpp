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

int fast_fib (int num)
{
  if (num <= 0) {
    return 0;
  }

  Zsqrt5 two_power = {1, 1};
  Zsqrt5 tot_power = {1, 0};

  int temp = num;
  while (temp > 0) {
    
    int b = temp & 1;
    if (b) {
      tot_power *= two_power;
    }

    two_power *= two_power;
    temp >>= 1;
  }

  static constexpr long double inv_sqrt5 = 0.4472135954999579L; // 1 / sqrt(5)
  long long fib = (long long)(tot_power.b + (long double)tot_power.a * inv_sqrt5);
  fib >>= num;

  fib += (num & 1);
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
