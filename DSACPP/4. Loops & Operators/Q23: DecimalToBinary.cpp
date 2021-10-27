/*
Decimal to Binary
Given a decimal number (integer N), convert it into binary and print.
The binary number should be in the form of an integer.
*/
#include "iostream"

using namespace std;

int main() {
    int decimalNumber;
    cin >> decimalNumber;
    long binaryNumber = 0;
    int multiplier = 1;
    int bit = 0;
    while (decimalNumber != 0) {
        bit = decimalNumber % 2;
        binaryNumber = binaryNumber + bit * multiplier;
        multiplier = multiplier * 10;
        decimalNumber = decimalNumber / 2;
    }
    cout << binaryNumber << endl;
}