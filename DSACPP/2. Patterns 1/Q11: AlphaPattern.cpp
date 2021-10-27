/*
Code : Alpha Pattern
Send Feedback
Print the following pattern for the given N number of rows.
Pattern for N = 3
A
BB
CCC
 */
#include "iostream"

using namespace std;

int main() {
    int numberOfLines;
    cout << "Enter the number of lines: ";
    cin >> numberOfLines;
    char startingCharacter = 'A';
    for (int row = 0; row < numberOfLines; row++) {
        for (int col = 0; col <= row; col++) {
            cout << startingCharacter;
        }
        startingCharacter++; //Increasing its ASCII value to get the next Character
        cout << endl;
    }
}