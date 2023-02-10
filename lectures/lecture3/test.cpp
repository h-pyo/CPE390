#include <iostream>
//int = whatever is fastest on your achine
//int >= 16 bits
// 2^16 = 65536
// -32768... 0 1 .. 32767 (because it counts 0 as a positive integer)
// int = 32 bits  -2.1 billion ... + 2.1billion

uint64_t add(uint64_t a, uint16_t b) {
    return a + b;
}

int f(int a) {
    return a*2;
}

int main() {
    std::cout << f(3) << '\n';
    uint64_t c = 2+3;
    uint64_t d = add(2,3);

}