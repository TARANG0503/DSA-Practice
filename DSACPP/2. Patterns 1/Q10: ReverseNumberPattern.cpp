/*
 * Code : Reverse Number Pattern
Print the following pattern for the given N number of rows.
Pattern for N = 4
1
21
321
4321
 */

#include "iostream"

using namespace std;

int main() {
    int numberOfLines;
    cout << "Enter the number of lines you want to print: ";
    cin >> numberOfLines;
    for (int i = 0; i < numberOfLines; i++) {
        for (int j = 0; j <= i; j++) {
            cout << i + 1 - j;
        }
        cout << endl;
    }

}