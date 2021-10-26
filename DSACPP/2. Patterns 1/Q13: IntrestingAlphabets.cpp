/*
Code : Interesting Alphabets
Print the following pattern for the given number of rows.
Pattern for N = 5
E
DE
CDE
BCDE
ABCDE
 */
#include "iostream"

using namespace std;

int main() {
    int numberOfLines;
    cout << "Enter the number of lines: ";
    cin >> numberOfLines;
    char startingCharacter;
    for (int row = 0; row < numberOfLines; row++) {
        startingCharacter = 'A' + numberOfLines - 1 - row;
        for (int col = 0; col <= row; col++) {
            cout << startingCharacter;
            startingCharacter++;
        }
        cout << endl;
    }
}