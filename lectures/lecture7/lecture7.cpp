#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  uint32_t a;  // 4 bytes

  float f = 1.2345678f;  // single precision IEEE 754
  f = 12.345678;
  f = 123.45678;
  f = 1.2345678e+23;  // x 10 to 23
  f = 1.234e+38;
  f = -1.234e+38;
  f = 1.234e-38;
  /*
  sign = +/-
  exponent (where to put the binary point)
  mantissa (the digits)
  .10101010111000000110101

  1.0 = 1
  10.0 = 2
  101.0 = 5
  .1 = 1/2
  .01 = 1/4
  .001 = 1/8

  1/3 = .3333333333333333333333333333333333
  1/10 = .1 (in decimal)
  */

  double d = 1.23456789012345;
  d = 1.234e+308;
  d = 1.234e-308;
  long double e;
  // quad precision is coming
  // half precision is here

  for (float x = 0; x < 10; x++) {
    cout << x << " ";
  }
  cout << "\n";
  for (float x = 0; x <= 10; x += 0.1f) {
    cout << x << " ";
  }
  cout << "\n";

  // integer divide by zero? CRASH! SIGFPE (floating point exception)
  // int x = 1 / 0;
  // cout << "What happens " << x << endl;

  float y = 1.0 / 0.0;
  cout << y << endl;
  double z = -3 / 0.0;      // -inf
  cout << (y + z) << endl;  // nan (not a number)
  /*
    what are the properties of numbers
    a + b == b + a (communative)
    (a + b) + c = a + (b + c) (this does not work with floating point)
  */

  float sum = 0;
  // sum of (1/1 + 1/2 + ... + 1/100) = 5.18
  for (int i = 1; i <= 100; i++) {
    sum += 1.0 / i;
  }
  cout << sum << endl;
}