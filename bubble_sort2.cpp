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
    // repetedly swap two adjacent elements if they are in wrong order
    for (int j = 1; j < n; j++)
        for (int i = 0; i < n - j; i++)
            if (array[i + 1] < array[i])
                swap(array[i], array[i + 1]);
    for (int i = 0; i < n; i++)
        cout << array[i];
    return 0;
}
