/*
Binary to decimal
Given a binary number as an integer N, convert it into decimal and print.
 */
#include "iostream"

using namespace std;

int main() {
    int binaryNumber;
    cin >> binaryNumber;
    int result = 0;
    int counter = 1;
    int digit = 0;
    while (binaryNumber != 0) {
        digit = binaryNumber % 10;  // to get whether it's a 1 or 0
        result = result + counter * digit;
        counter = counter * 2;
        binaryNumber /= 10;
    }
    cout << result;
}