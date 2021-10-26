/*
 * Square Root (Integral)
Given a number N, find its square root. You need to find and print only the integral part of square root of N.
For eg. if number given is 18, answer is 4.
 */
#include "iostream"

using namespace std;

int main() {
    int number;
    cin >> number;
    int counter = 1;
    while (counter * counter <= number) {
        counter++;
    }
    cout << counter - 1 << endl;
}