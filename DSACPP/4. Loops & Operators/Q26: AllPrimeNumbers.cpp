/*
All Prime Numbers
Given an integer N, print all the prime numbers that lie in the range 2 to N (both inclusive).
Print the prime numbers in different lines.
 */
#include "iostream"

using namespace std;

int main() {
    int number;
    cin >> number;
    int counter = 2;
    while (counter <= number) {
        int divisor = 0;
        int secondCounter = 2;
        while (secondCounter <= counter / 2) {
            if (counter % secondCounter == 0) {
                divisor++;
                break;
            }
            secondCounter++;
        }
        if (divisor == 0) {
            cout << counter << endl;
        }
        counter++;
    }
}