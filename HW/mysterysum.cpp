#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  const int n = atoi(argv[1]);
  float sum1 = 0;  // forwards
  float sum2 = 0;  // backwards
  // 1 / (1*1) + 1/(2*2) + 1/ (3*3) ... up to 1 / (n*n)

  for (float i = 1; i <= n; i++) {
    sum1 += 1.0 / (i * i);
  }

  // compute the sum forwards and backwards
  cout << 6 * sqrt(sum1) << endl;
  cout << 6 * sqrt(sum2) << endl;
}