/*
Terms of AP
Write a program to print first x terms of the series 3N + 2 which are not multiples of 4.
Input format :
Integer x
10
5 11 14 17 23 26 29 35 38 41
*/
#include "iostream"

using namespace std;

int main() {
    int numberOfTerms;
    cout << "Number of terms you want to print: ";
    cin >> numberOfTerms;
    int counter = 1;
    int startingValue = 5;
    while (counter <= numberOfTerms) {
        if (startingValue % 4 == 0) {
            counter--;
        } else {
            cout << startingValue << " ";
        }
        counter++;
        startingValue += 3;
    }
    cout << endl;
}