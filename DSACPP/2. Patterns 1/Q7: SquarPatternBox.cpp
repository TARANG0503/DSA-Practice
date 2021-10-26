/*
Code : Square Pattern
Print the following pattern for the given N number of rows.
Pattern for N = 4
        4444
        4444
        4444
        4444
*/
#include "iostream"

using namespace std;

int main() {
    int numberOfLines;
    cout << "Enter the value/number of lines you want: ";
    cin >> numberOfLines;
    for (int i = 0; i < numberOfLines; i++) {
        for (int j = 0; j < numberOfLines; j++) {
            cout << numberOfLines;
        }
        cout << endl;
    }
}