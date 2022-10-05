#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int array[n];
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++)
        cin >> array[i];

    // Find min element of unsorted array and swap it with element at beginning
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (array[j] < array[i])
                swap(array[i], array[j]);
    for (int i = 0; i < n; i++)
        cout << array[i] << " ";
    return 0;
}
