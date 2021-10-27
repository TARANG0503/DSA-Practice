/*
Code : Triangle Number Pattern
Print the following pattern for the given N number of rows.
Pattern for N = 4
1
22
333
4444
*/
#include "iostream"

using namespace std;

int main() {
    int numberOfLines;
    cout << "Enter the number of lines: ";
    cin >> numberOfLines;
    for (int i = 0; i < numberOfLines; i++) {
        for (int j = 0; j <= i; j++) {
            cout << i + 1;
        }
        cout << endl;
    }
}