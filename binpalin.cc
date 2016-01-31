/******** Binary Palindrome **********
    Determine whether a given integer is a binary palindrome.
*************************************/

#include <iostream>
using namespace std;

// compute the binary reverse-order number of n, then compare it with n
bool isBinPalin(const int n) {
    unsigned int m = n;
    unsigned int sum = 0;
    while (m > 0) {
        sum <<= 1;
        sum += m & 1;
        m >>= 1;
    }
    return n == sum;
}

int main(void) {
    int n;
    cin >> n;
    cout << isBinPalin(n) << endl;
    return 0;
}
