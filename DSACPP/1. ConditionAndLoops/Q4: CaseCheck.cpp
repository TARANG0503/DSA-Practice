/*
Check Case
Write a program that takes a character as input and prints either 1, 0 or -1 according to the following rules.
1, if the character is an uppercase alphabet (A - Z)
0, if the character is a lowercase alphabet (a - z)
-1, if the character is not an alphabet
*/
#include "iostream"

using namespace std;

int main() {
    char userChar; // we will compare ASCII code for the character
    cout << "Enter the character: ";
    cin >> userChar;
    int answer;
    if (userChar >= 65 && userChar <= 90) {  // ASCII value for capital alphabet is between 65 and 90
        answer = 1;
    } else if (userChar >= 97 && userChar <= 122) { // ASCII value for small alphabet is between 97 and 122
        answer = 0;
    } else {
        answer = -1;
    }
    cout << answer << endl;
}