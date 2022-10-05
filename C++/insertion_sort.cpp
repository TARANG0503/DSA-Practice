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

    // insert an element from unsorted array to its correct position in sorted array

    for (int i = 1; i < n; i++)
    {
        int current = array[i], j = i - 1;
        while (array[j] > current && j >= 0)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = current;
    }
    for (int i = 0; i < n; i++)
        cout << array[i] << " ";
    return 0;
}
