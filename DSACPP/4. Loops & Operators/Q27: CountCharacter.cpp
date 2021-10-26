/*
 * Count Characters
Write a program to count and print the total number of characters (lowercase english alphabets only),
digits (0 to 9) and white spaces (single space, tab i.e. '\t' and newline i.e. '\n') entered till '$'.
That is, input will be a stream of characters & you need to consider all the characters which are entered till '$'.
Print count of character, count of digits and count of white spaces respectively (separated by space).
Input Format :
A stream of characters terminated by '$'
 */
#include "iostream"

using namespace std;

int main() {
    char c = 'a';
    int character = -1;
    int whitespace = 0;
    int digit = 0;
    while (c != '$') {
        if (c == 32) { // Comparing ASCII code
            whitespace++;
        } else if (c > 47 && c < 57) {
            digit++;
        } else {
            character++;
        }
        cin.get(c); // because normal cin doesn't capture whitespace
    }
    cout << character << "\t" << digit << "\t" << whitespace << endl;
}