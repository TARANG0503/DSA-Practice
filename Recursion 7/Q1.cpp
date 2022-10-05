#include <iostream>
using namespace std;

void mergeArr(int *arr, int start, int end, int &countInv)
{
    int mid = start + (end - start) / 2;

    int size1 = mid - start + 1;
    int size2 = end - mid;

    int *arr1 = new int[size1];
    int *arr2 = new int[size2];

    int k = start;

    for (int i = 0; i < size1; i++)
    {
        arr1[i] = arr[k++];
    }

    k = mid + 1;

    for (int i = 0; i < size2; i++)
    {
        arr2[i] = arr[k++];
    }

    int ptr1 = 0;
    int ptr2 = 0;

    k = start;

    while (ptr1 < size1 && ptr2 < size2)
    {
        if (arr2[ptr2] < arr1[ptr1])
        {
            arr[k++] = arr2[ptr2++];

            countInv += size1 - ptr1;
        }
        else // arr1[ptr1] < arr2[ptr2]
        {
            arr[k++] = arr1[ptr1++];
        }
    }

    while (ptr1 < size1)
    {
        arr[k++] = arr1[ptr1++];
    }

    while (ptr2 < size2)
    {
        arr[k++] = arr2[ptr2++];
    }

    delete[] arr1;
    delete[] arr2;
}

void mergeSort(int *arr, int start, int end, int &countInv)
{
    if (start >= end)
    {
        return;
    }

    int mid = start + (end - start) / 2;

    mergeSort(arr, start, mid, countInv);

    mergeSort(arr, mid + 1, end, countInv);

    mergeArr(arr, start, end, countInv);
}

int main()
{
    int n;
    cin >> n;

    int countInv = 0;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1, countInv);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    cout << countInv;

    delete[] arr;

    return 0;
}

//----------------------approch 2-----------------------

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    long long int mergeArr(long long *arr, long long start, long long end)
{
     long long int mid = start + (end - start) / 2;
    
    long long int countInv = 0;

     long long int size1 = mid - start + 1;
     long long int size2 = end - mid;

     long long *arr1 = new  long long [size1];
     long long *arr2 = new  long long [size2];

     long long int k = start;

    for (int i = 0; i < size1; i++)
    {
        arr1[i] = arr[k++];
    }

    k = mid + 1;

    for (int i = 0; i < size2; i++)
    {
        arr2[i] = arr[k++];
    }

     long long int ptr1 = 0;
     long long int ptr2 = 0;

    k = start;

    while (ptr1 < size1 && ptr2 < size2)
    {
        if (arr2[ptr2] < arr1[ptr1])
        {
            arr[k++] = arr2[ptr2++];
            
            countInv += size1 - ptr1;
        }
        else
        {
            arr[k++] = arr1[ptr1++];
        }
    }

    while (ptr1 < size1)
    {
        arr[k++] = arr1[ptr1++];
    }

    while (ptr2 < size2)
    {
        arr[k++] = arr2[ptr2++];
    }
    
    return countInv;
    
    delete [] arr1;
    delete [] arr2;
}

long long int mergeSort(long long *arr, long long start, long long end)
{
    long long int countInv = 0;
    
    if (start < end)
    {

     long long int mid = start + (end - start) / 2;

    countInv += mergeSort(arr, start, mid);

    countInv += mergeSort(arr, mid + 1, end);

    countInv += mergeArr(arr, start, end);
    }
    
    return countInv;
}
    long long int inversionCount(long long arr[], long long N)
    {
       long long int ans = mergeSort(arr, 0, N - 1);
       
       return ans;
    }

};

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}