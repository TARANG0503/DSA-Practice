/*
Problem Statement: Duplicate in array
Problem Level: EASY
Problem Description:
You have been given an integer array/list(ARR) of size N which contains numbers from 0 to (N - 2).
Each number is present at least once.
That is, if N = 5, the array/list constitutes values ranging from 0 to 3, and among these, there is a single integer value that is present twice.
You need to find and return that duplicate number present in the array.
Note :
Duplicate number is always present in the given array/list.
 */
#include "iostream"
using namespace std;
int main(){
    int len;
    cin >> len;
    int *arr = new int[len];
    for(int i =0; i< len;i++){
        cin >> arr[i];
    }
    int index;
    for(int i = 0;i<len;i++){
        index = abs(arr[i]);
        if(arr[index]<0) break;
        arr[index] = -arr[index];
    }
    cout << index<<endl;
}