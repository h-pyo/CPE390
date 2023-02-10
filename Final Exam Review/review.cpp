#include <bits/stdc++.h>

#include <cmath>
#include <iostream>
using namespace std;

double eval(double arr[], int len, double x) {
  double result = 0;
  for (int i = 0; i < len; i++) {
    if (i == (len - 1)) {
      result += arr[i];
    } else {
      result += arr[i];
      result *= x;
    }
  }
  return result;
}

double mean(int arr[], int len) {
  double result = 0.0;
  for (int i = 0; i < len; i++) {
    result += arr[i];
  }
  return result / len;
}

void reverse(char arr[]) {
  int len = 0;
  for (int i = 0; arr[i] != '\0'; i++) {
    len++;
  }
  cout << len << endl;
  char temp;
  for (int i = 0; i < len / 2; i++) {
    temp = arr[i];
    arr[i] = arr[len - 1 - i];
    arr[len - 1 - i] = temp;
  }
}

uint32_t color(uint32_t r, uint32_t g, uint32_t b) {
  uint32_t result = 0;
  result |= r;
  result <<= 8;
  result |= g;
  result <<= 8;
  result |= b;
  return result;
}

int main() {
  int array[] = {1, 2, 3, 4};
  double avg = mean(array, 4);  // mean is 2.5 in this example
  cout << avg << endl;
  cout << endl;

  double coef[] = {5, -3, 2, 1, 4};
  // evaluate the polynomial 5x^4 - 3x^3 + 2x^2 + x + 4 with x=2.5
  // do this using Horner's form, in a loop:
  // keep multiplying by x and adding each coefficient, like this
  // (but in a loop)
  // ((coef[0] * x + coef[1]) * x + coef[2]) * x + ...
  double evaluate = eval(coef, 5, 2.5);
  cout << evaluate << endl;
  cout << endl;

  // in c a string ends with the last character whose ASCII code is '\0'
  // (which is not the digit 0, it's control-@, a non-printable character)
  char s[] = "this is my string\0";
  reverse(s);  // s should contain: gnirts ym si siht
  for (char x : s) {
    cout << x;
  }
  cout << endl;

  // "hello\0" hello
  // swap the two variables a and b using xor
  int a = 3;
  int b = 4;
  a = a ^ b;
  a = a ^ b;  // 011 XOR 100 = 111 = 7
  b = a ^ b;  // 111 XOR 100 = 3
  a = a ^ b;

  a = 15 - a;
  if (a == 0)
    a = 15;
  else
    a = 0;

  // reverse the bits of a 1000 == > 0001 FFT needs bit reversal brev % rcx

  // int len;
  // for (len = 0; s[len] != '\0'; len++);
  // // len = length of the string s
  // for (int i = 0; i < len / 2; i++) {
  //   char temp = s[i];
  //   s[i] = s[len - 1 - i];
  //   s[len - 1 - i] = temp;

  //   s[i] += s[len - 1 - i];  // s[i] = sum of both
  //   s[len - 1 - i] = s[i] - s[len - 1 - i] s[i] = s[i] - s[len - 1 - i]
  // }

  // Write a function to combine three 8-bit numbers r,g,b into a single color
  // value the number should be rrrrrrrrggggggggbbbbbbbb where b is low
  // order bits
  uint32_t x = 10;
  uint32_t y = 10;
  uint32_t z = 10;
  uint32_t result = color(x, y, z);
  cout << result << endl;
}