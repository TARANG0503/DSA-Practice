/*
Code : Star Pattern
Print the following pattern
Pattern for N = 4
  *
 ***
******
*/
#include "iostream"

using namespace std;

int main() {
    int numberOfLines;
    cout << "Enter the number of lines: ";
    cin >> numberOfLines;
    int numberOfSpace;
    int stars = 1;
    for (int i = 0; i < numberOfLines; i++) {
        numberOfSpace = numberOfLines - i - 1;
        for (int j = 0; j < numberOfSpace; j++) {
            cout << " ";
        }
        for (int star = 0; star < stars; star++) {
            cout << "*";
        }
        cout << endl;
        stars += 2;

    }
}