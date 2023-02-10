#include <iostream>
#include <math.h>
using namespace std;

// iterates through the powers of 2 from 0-33 when the function is called
void powersOfTwo() {
    uint32_t num = 33;
    uint32_t two = 2;
    //iterates from 0 to 33 and prints the powers of 2
    for (int i = 0; i < num; i++) {
        uint32_t result = pow(two,i);
        cout << result << endl;
    }
}

int sumOfSquares(int a, int b) {
    int sum = 0;
    //iterate from a to b and add the square of the current number to the total sum
    for (int i = a; i <= b; i++)  {
        sum += pow(i,2);
    }
    return sum;
}
/*
	.globl	_Z12sumOfSquaresii
	.def	_Z12sumOfSquaresii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z12sumOfSquaresii
_Z12sumOfSquaresii:
.LFB2462:
	.seh_endprologue
	cmpl	%edx, %ecx
	jg	.L23
	addl	$1, %edx
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L22:
	pxor	%xmm0, %xmm0
	pxor	%xmm1, %xmm1
	cvtsi2sdl	%ecx, %xmm0
	addl	$1, %ecx
	cvtsi2sdl	%eax, %xmm1
	mulsd	%xmm0, %xmm0
	addsd	%xmm0, %xmm1
	cvttsd2sil	%xmm1, %eax
	cmpl	%edx, %ecx
	jne	.L22
	ret
	.p2align 4,,10
	.p2align 3
*/

//returns the factorial of a number
int factorial(int a) {
    int result = 1;
//iterates from 1 to the number(a) and multiplying itself with the next until it reaches a
    for (int i = 1; i <=a; i++) {
        result = result * i;
    }
    return result;
}

int main() {
    cout << "Part 1:" << endl;
    powersOfTwo();
    cout << "Part 2:" << endl;
    cout << "/////////////////////////////////////////////" << endl;
    int result = sumOfSquares(3,42);
    cout << result << endl;
    cout << "Part 3:" << endl;
    cout << "/////////////////////////////////////////////" << endl;
    for (int i = 1; i <= 25; i++) {
        cout << factorial(i) << endl;
    }
}

