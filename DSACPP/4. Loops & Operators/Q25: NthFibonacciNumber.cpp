/*
Nth Fibonacci Number
Nth term of fibonacci series F(n) is calculated using following formula -
    F(n) = F(n-1) + F(n-2),
    Where, F(1) = F(2) = 1
Provided N you have to find out the Nth Fibonacci Number.
*/
#include "iostream"

using namespace std;

int fibonacci(int n) {
    if (n == 2) {
        return 1;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;
}