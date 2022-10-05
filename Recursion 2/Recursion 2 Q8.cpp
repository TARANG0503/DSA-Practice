#include <iostream>
using namespace std;

int sumofArray(int *arr, int n, int sum)
{
    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return arr[0];
    }

    sum = arr[0] + sumofArray(arr + 1, n - 1, sum);

    return sum;
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int sum = 0;

    cout << sumofArray(arr, n, sum);

    delete[] arr;

    return 0;
}