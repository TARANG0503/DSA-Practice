/*  _________
 *  | N = 4 |
 *  |   *   |
 *  |  ***  |
 *  | ***** |
 *  |*******|
 *
 *
 */
#include "iostream"

using namespace std;

int main() {
    int numberOfLines;
    cout << "Enter the number of lines you want: ";
    cin >> numberOfLines;
    int numberOfStar = 1;
    while (numberOfLines != 0) {
        int numberOfSpace = numberOfLines - 1;
        while (numberOfSpace != 0) { // To print the number of space before star
            cout << " ";
            numberOfSpace--;
        }
        for (int i = 0; i < numberOfStar; i++) { // This is to print number of start in one line
            cout << "*";
        }
        numberOfStar += 2; // Incementing number of star per line
        numberOfLines -= 1;
        cout << endl;
    }
}