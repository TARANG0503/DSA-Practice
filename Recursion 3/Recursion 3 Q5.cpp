#include <iostream>
using namespace std;

void selectionSort(int *arr, int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }

    int smallestIndex = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[smallestIndex])
        {
            smallestIndex = i;
        }
    }
    swap(arr[0], arr[smallestIndex]);

    selectionSort(arr + 1, n - 1);
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

    selectionSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    delete[] arr;

    return 0;
}