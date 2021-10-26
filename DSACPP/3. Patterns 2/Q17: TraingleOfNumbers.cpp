/*
Code : Triangle of Numbers
Print the following pattern for the given number of rows.
Pattern for N = 5
    1
   232
  34543
 4567654
567898765
*/
#include "iostream"

using namespace std;

int main() {
    int numberOfLines;
    cout << "Enter the number of lines: ";
    cin >> numberOfLines;
    int mainCounter = 1; // This is the main Counter we will print
    int numberOfSpace = numberOfLines - 1;
    for (int i = 0; i < numberOfLines; i++) {
        for (int space = 0; space < numberOfSpace; space++) {
            cout << " "; // for spaces
        }
        for (int j = 0; j <= i; j++) {
            cout << mainCounter; //Breaking the problem into two triangles this is the first triangle
            mainCounter++;
        }
        mainCounter--;
        for (int k = 0; k < i; k++) {
            mainCounter--; // THis is second triangle in the same line i.e. next part
            cout << mainCounter;
        }
        mainCounter++;
        cout << endl;
        numberOfSpace--;
    }
}