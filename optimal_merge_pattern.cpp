/*
Algorithm-

Step 1: Build a min heap with given array.
Step 2: Extract two minimum from the heap.
Step 3: Store the sum of two minimums.
Step 4: Add the sum of two minimum's into heap.
        Repeat all four steps above until there is only one element left in heap.
Step 5: Print the sum of minimums.
*/

#include<iostream>
#include<conio.h>
#include<iomanip>
using namespace std;

void build_min_heap(int*, int);
void heapify(int*, int, int);
void Print(int*, int);

int main()
{
    int n=5;
    int arr[] = {5, 10, 20, 30, 30};

    //Creating a min heap
    build_min_heap(arr, n);
    Print(arr, n);
    getch();
    int temp = n, total_cost = 0;
    while(temp>1)
    {
        //Extracting First minimum
        swap(arr[0], arr[--temp]);
        //Heapifying after first extraction
        heapify(arr, temp, 0);
        //Extracting second minimum
        swap(arr[0], arr[temp-1]);
        //Finding the minimum's sum, storing it and adding the sum into heap
        total_cost += arr[temp-1] += arr[temp];
        //Building the min heap again after addition of new node in it.
        build_min_heap(arr, temp);
        Print(arr, n);
        getch();
    }
    cout<<"Final Cost: "<<total_cost<<endl;
}

void build_min_heap(int *arr, int n)
{
    for(int i=n/2; i>=0; i--)
        heapify(arr, n, i);
}

void heapify(int *arr, int n , int i)
{
    int left=i*2+1, right=i*2+2;
    int min_ind = i;
    if(left<n && arr[min_ind] > arr[left])
        min_ind = left;
    if(right<n && arr[min_ind] > arr[right])
        min_ind = right;
    if(min_ind == i)
        return;
    else
        swap(arr[i], arr[min_ind]);
    heapify(arr, n, min_ind);
}

void Print(int *arr, int n)
{
    cout<<">>> ";
    for(int i=0; i<n; i++)
        cout<<setw(3)<<arr[i]<<" ";
    cout<<endl;
}
