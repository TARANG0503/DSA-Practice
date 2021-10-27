/*
Code : Mirror Number Pattern
Print the following pattern for the given N number of rows.
Pattern for N = 3
  1
 12
123
 */
#include "iostream"

using namespace std;

int main() {
    int numberOfLines;
    cout << "Enter the number of lines: ";
    cin >> numberOfLines;
    int counter;
    for (int row = 0; row < numberOfLines; row++) {
        counter = 1; // After every row counter reset
        for (int space = 0; space < numberOfLines - row - 1; space++) { // This loop is for the number of space
            cout << " ";
        }
        while (counter <= row + 1) { // To print number
            cout << counter;
            counter++;
        }
        cout << endl;
    }
}