/*
Reverse of a number
Write a program to generate the reverse of a given number N. Print the corresponding reverse number.
Note : If a number has trailing zeros, then its reverse will not include them. For e.g., reverse of 10400 will be 401 instead of 00401.
*/

#include "iostream"

using namespace std;

int main() {
    int number;
    cin >> number;
    int result = 0;
    int digit = 0;
    while (number != 0) {
        digit = number % 10;
        result = result * 10 + digit;
        number /= 10;
    }
    cout << result << endl;
}