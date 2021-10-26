/*
Code : Inverted Number Pattern
Print the following pattern for the given N number of rows.
Pattern for N = 4
4444
333
22
1
*/
#include "iostream"

using namespace std;

int main() {
    int numberOfLines;
    cout << "Enter the number of lines: ";
    cin >> numberOfLines;
    int counter = 0;
    int printCounter;
    while (counter < numberOfLines) {
        printCounter = numberOfLines - counter;
        for (int j = 0; j < printCounter; j++) {
            cout << printCounter;
        }
        cout << endl;
        counter++;
    }
}