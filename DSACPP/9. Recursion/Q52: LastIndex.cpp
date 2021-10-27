/*
Problem Statement: Last index of x
Problem Level: MEDIUM
Problem Description:
Given an array of length N and an integer x, you need to find and return the last index of integer x present in the array. Return -1 if it is not present in the array.
Last index means - if x is present multiple times in the array, return the index at which x comes last in the array.
You should start traversing your array from 0, not from (N - 1).
Do this recursively. Indexing in the array starts from 0.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
*/

#include "iostream"
using namespace std;

int lastIndex(int arr[],int len,int x){
    if(len==0){
        return -1;
    }
    if(arr[len-1] == x){
        return len-1;
    }
    return lastIndex(arr,len-1,x);
}

int main(){
    int len,x;
    cin >> len;
    int *arr = new int[len];
    int counter = 0;
    while (counter<len){
        cin >> arr[counter];
        counter++;
    }
    cin >> x;
    cout << lastIndex(arr,len,x)<<endl;

}