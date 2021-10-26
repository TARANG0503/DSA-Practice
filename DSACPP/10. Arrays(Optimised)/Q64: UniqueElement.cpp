/*
Problem Statement: Find the Unique Element
Problem Level: MEDIUM
Problem Description:
You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].
Now, in the given array/list, 'M' numbers are present twice and one number is present only once.
You need to find and return that number which is unique in the array/list.
Note:
Unique element is always present in the array/list according to the given condition.
 */
#include "iostream"
using namespace std;

int main(){
    int len;
    cin >> len;
    int *arr = new int[len];
    for(int i = 0;i<len;i++){
        cin>> arr[i];
    }
    int res = 0;
    for(int i = 0;i<len;i++){
        res = res ^ arr[i];   // Using XOR Gate here since x^x = 0 & 0^y = y and XOR GATE is associative
    }
    cout << res << endl;
}