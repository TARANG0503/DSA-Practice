/*
Sum of even & odd
Write a program to input an integer N and print the sum of all its even digits and sum of all its odd digits separately.
Digits mean numbers, not the places! That is, if the given integer is "13245", even digits are 2 & 4 and odd digits are 1, 3 & 5.
Input format :
Integer N
Output format :
Sum_of_Even_Digits Sum_of_Odd_Digits
(Print first even sum and then odd sum separated by space)
*/
#include "iostream"

using namespace std;

int main() {
    int number;
    int evenSum = 0;
    int oddSum = 0;
    int digit; // To save the one digit of the number
    cout << "Enter the number: ";
    cin >> number;
    while (number != 0) {
        digit = number % 10; // Modulus 10 to get the remainder .i.e. last most digit of the number
        if (digit % 2 == 0) {
            evenSum += digit;
        } else {
            oddSum += digit;
        }
        number = number / 10;
    }
    cout << evenSum << " " << oddSum << endl;
}