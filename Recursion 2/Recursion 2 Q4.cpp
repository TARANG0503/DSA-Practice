#include <iostream>
using namespace std;

void numspell(int n, string arr[])
{
    if (n == 0)
    {
        return;
    }

    int digit = n % 10;
    n = n / 10;

    numspell(n, arr);

    cout << arr[digit] << " ";
}

int main()
{
    int n;
    cin >> n;

    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    numspell(n, arr);

    return 0;
}