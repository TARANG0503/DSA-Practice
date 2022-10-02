#include <bits/stdc++.h>
using namespace std;
// finding the maximum element function
//  calling the maximum element function in the count sort.
// display function for displaying the array.

void PrintArray(int array[], int size) // function used for displaying the array.
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i];
        if (i == size - 1)
        {
            cout << " ";
        }
        else
        {
            cout << ",";
        }
    }
    cout << endl;
}
int finding_max_element(int array[], int size)
{
    int element;
    int sub_array[size];
    int number_of_elements = sizeof(sub_array) / sizeof(sub_array[0]);
    for (int i = 0; i < size; i++)
    {
        sub_array[i] = array[i];
    }
    sort(sub_array, sub_array + number_of_elements);
    element = sub_array[size - 1];
    return element;
}
void count_sort(int Array[], int size)
{
    int max_size_element = finding_max_element(Array, size);
    int count_sort_Array[max_size_element + 1];
    int j = 0, k = 0, l = 0, m = 0;
    for (int i = 0; i < (max_size_element + 1); i++) // In starting of the element we have to fill the array with the 0.
    {
        count_sort_Array[i] = 0;
    }
    while (j < size)
    {
        while (k != Array[j]) // for finding the index postiion in the new Array and increament the value in that index postion by 1.
        {
            k++;
        }
        count_sort_Array[k]++;
        j++;
        k = 0; // by resetting the value we can find the index position in the given new array
        // and increament  the value in the given new array by 1.
    }

    while (l < (max_size_element + 1))
    {
        if (count_sort_Array[l] == 0)
        {
            l++;
        }
        else
        {
            while (count_sort_Array[l] > 0)
            {
                Array[m] = l;
                m++;
                count_sort_Array[l]--;
            }
            l++;
        }
    }
}
int main()
{
    int size;
    cout << "Enter the size of the Array: ";
    cin >> size;
    int array[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the element " << i + 1 << " in the Array: ";
        cin >> array[i];
    }
    count_sort(array, size);
    cout << "Sorted Array is: ";
    PrintArray(array, size);

    return 0;
}