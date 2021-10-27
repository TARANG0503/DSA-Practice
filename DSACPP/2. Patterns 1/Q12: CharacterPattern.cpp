/*
Code : Character Pattern
Print the following pattern for the given N number of rows.
Pattern for N = 4
A
BC
CDE
DEFG
*/

#include "iostream"

using namespace std;

int main() {
    int numberOfLines;
    cout << "Enter the number of lines: ";
    cin >> numberOfLines;
    char startingCharacter = 'A';
    for (int row = 0; row < numberOfLines; row++) {
        startingCharacter = 'A' + row; // To get the next character according to row we are currently in.
        for (int col = 0; col <= row; col++) {
            cout << startingCharacter;
            startingCharacter++;
        }
        cout << endl;
    }
}