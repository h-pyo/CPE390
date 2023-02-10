#include <iostream>
using namespace std;

int f(int a, int b) {
    return a + b;
}

#if 0
double f (double a, double b) {
    return a + b;
}
#endif

int main() {
    int result = f(2,3);
    cout << result << endl;
}

//write a function that counts powers of 2
// use uint32_t
// multiply each time 1, 2, 4, 8, 16
//repeat 33 times

// write a function to sum the square between a and b
 cout << sumsquares(3,32);
 // show the assembler
 // complie using g++ 02
 /*
 your assembler goes here
 
 */

// n = 1 to 25
// compute the factorial of n