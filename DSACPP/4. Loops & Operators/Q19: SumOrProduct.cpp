/*
 * Sum or Product
Write a program that asks the user for a number N and a choice C.
And then give them the possibility to choose between computing the sum and computing the product of all integers in the range 1 to N (both inclusive).
If C is equal to -
 1, then print the sum
 2, then print the product
 Any other number, then print '-1' (without the quotes)
 */
int sum(int num) {
    int counter = 1;
    int result = 0;
    while (counter <= num) {
        result += counter;
        counter++;
    }
    return result;
}

int prod(int num) {
    int result = 1;
    int counter = 1;
    while (counter <= num) {
        result *= counter;
        counter++;
    }
    return result;
}

#include "iostream"

using namespace std;

int main() {
    int number, choice;
    cout << "Enter the number and choice: 1 for sum, 2 for product - ";
    cin >> number >> choice;
    if (choice == 1) {
        cout << sum(number);
    } else if (choice == 2) {
        cout << prod(number);
    } else {
        cout << -1;
    }
    cout << endl;

}