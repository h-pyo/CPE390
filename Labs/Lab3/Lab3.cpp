//"I pledge my honor that I have abided by the Stevens Honor System."
// - Harris Pyo, Justin Chen
#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
int countEvens(int x[], int n) {
  int result = 0;
  for (int i = 0; i < n; i++) {
    if (x[i] % 2 == 0) {
      result++;
    }
  }
  return result;
}
void addToEach(float x[], int n, float delta) {
  for (int i = 0; i < n; i++) {
    x[i] += delta;
  }
}
void range_reverse(int x[], int n, int a, int b) {
  int temp = 0;
  while (a <= b) {
    temp = x[a];
    x[a] = x[b];
    x[b] = temp;
    a++;
    b--;
  }
}
void compact(int x[], int n, int a, int b) {
  int index = b + 1;
  for (int i = a; i < n; i++) {
    if (i <= b) {
      if (index < n) {
        x[i] = x[index];
        index++;
      } else {
        x[i] = 0;
      }
    } else if (index < n) {
      x[i] = x[index];
      index++;
    } else {
      x[i] = 0;
    }
  }
}
uint32_t color(uint8_t r, uint8_t g, uint8_t b) {
  uint32_t result = 0;
  result |= r;
  result <<= 8;
  result |= g;
  result <<= 8;
  result |= b;
  return result;
}
void extractrgb(uint32_t color, uint8_t& r, uint8_t& g, uint8_t& b) {
  r = (color & 0xFF0000) >> 0x10;
  g = (color & 0x00FF00) >> 0x08;
  b = (color & 0x0000FF);
}
int singleNumber(int x[], int n) {
  int index = 0;
  for (int i = 0; i < n; i++) {
    bool found = false;
    for (int j = 0; j < n; j++) {
      if (j != i) {
        if ((x[i] ^ x[j]) == 0) {
          found = true;
          break;
        }
      }
    }
    if (!found) {
      index = i;
    }
  }
  return x[index];
}

int main() {
  // example for bit operation
  cout << "Question 1-----------------------------------" << endl;
  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int res1 = countEvens(arr1, sizeof(arr1) / sizeof(int));
  cout << "# even numbers: " << res1 << endl;
  cout << "Question 2-----------------------------------" << endl;
  float arr2[] = {1.0, 2.0, 3.0, 4.0};
  float delta = 0.5;
  addToEach(arr2, sizeof(arr2) / sizeof(arr2[0]), delta);
  cout << "array after added delta is:" << endl;
  for (auto a : arr2) {
    cout << a << ", ";
  }
  cout << endl;
  cout << "Question 3-----------------------------------" << endl;
  int arr3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  range_reverse(
      arr3, sizeof(arr3) / sizeof(int), 1,
      4);  // reverse element between index 1 and 4, -> 1,5,4,3,2,6,7,8,9,10
  cout << "array after range reverse is:" << endl;
  for (auto a : arr3) {
    cout << a << ", ";
  }
  cout << endl;
  cout << "Question 4-----------------------------------" << endl;
  int arr4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  compact(arr4, sizeof(arr4) / sizeof(int), 1, 4);
  cout << "array after compact is:"
       << endl;  // after compact, array should be 1,6,7,8,9,10,0,0,0,0
  for (auto a : arr4) {
    cout << a << ", ";
  }
  cout << endl;
  cout << "Question 5 & 6-------------------------------" << endl;
  uint32_t c = color(0xFF, 0x80, 0x00);  // should be 0xFF8000
  cout << hex << c << '\n';
  uint8_t r, g, b;
  extractrgb(c, r, g, b);
  cout << "r=" << bitset<8>(r) << " g=" << bitset<8>(g) << " b=" << bitset<8>(b)
       << endl;
  cout << "Question 7-----------------------------------" << endl;
  int x[] = {1, 1, 2, 3, 3, 4, 4, 5, 5};
  int res7 = singleNumber(x, 9);
  cout << "the single number is :" << res7 << endl;
  return 0;
}