#include <iostream>
using namespace std;

double mean(const int a[], int n) {
    double result = 0;
    for (int i = 0; i < n; i++) {
        result += a[i];
    }
    return result / n;
}

int main() {
    int a[] = {5, 3, 1, 9};
    double z = mean(a, 4);
    cout << z << "\n";
}