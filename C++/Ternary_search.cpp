/* Implementation of very helpful algorithm in advance competitive programming- Ternary Search
Ternary Search is similar to Binary Search, but here we divide the array into three parts instead of two parts, and then perform searching. */

#include <bits/stdc++.h>
using namespace std;
#define for(a, b) for (int i = a; i < b; i++)
#define printArr(arr, n) for(0, n) printf("%d ", arr[i]); printf("\n");
#define endl "\n"

int ternary_search(int *, int, int);

int main(int argc, char const *argv[])
{
	int n = 50;
	int array[n];
	for(0, n)
		array[i] = (rand() % 150) + 1;	// storing random values between 1 to 150
	cout << "Initial array: ";
	printArr(array, n);
	// Ternary Search is similar to Binary Search, therefore, this will be applicable on sorted array only.
	// So sorting the array for our use. If getting sorted array, no need to perform sorting.
	sort(array, array + n);
	cout << "\nArray after sorting: ";
	printArr(array, n);

	int key;
	cout << "Enter the value to search in array: ";
	cin >> key;

	int key_idx = ternary_search(array, n, key);

	if (key_idx == -1)
	{
		cout << key << " not present in the array." << endl;
	} else
	{
		cout << key << " found at index " << key_idx << "." << endl;
	}

	return 0;
}

int ternary_search(int arr[], int n, int key)
{
	int l = 0, r = n - 1;
	while (l <= r)
	{
		// finding the mid1 and mid2
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        // checking whether key is at any of the mid values
        if (arr[mid1] == key)
        {
        	return mid1;
        }
        if (arr[mid2] == key)
        {
        	return mid2;
        }

        // Checking which segment our key is lying
        if (arr[mid1] > key)
        {
        	r = mid1 - 1;
        } else if (arr[mid2] < key)
        {
        	l = mid2 + 1;
        } else
        {
        	l = mid1 + 1;
        	r = mid2 - 1;
        }
	}
	return -1;
}
