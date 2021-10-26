/*
Find power of a number
Write a program to find x to the power n (i.e. x^n). Take x and n from the user. You need to print the answer.
Note : For this question, you can assume that 0 raised to the power of 0 is 1
*/
#include "iostream"

using namespace std;

int main() {
    int number;
    int power;
    int answer = 1; // To save the answer
    cin >> number >> power;
    while (power != 0) {
        answer = answer * number;
        power--;
    }
    cout << answer << endl;
}