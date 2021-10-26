/*
Problem Statement: First Index
Problem Level: EASY
Problem Description:
Given an array of length N and an integer x, you need to find and return the first index of integer x present in the array. Return -1 if it is not present in the array.
First index means, the index of first occurrence of x in the input array.
Do this recursively. Indexing in the array starts from 0.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
first index or -1
*/
#include "iostream"
using namespace std;
int firstIndex(int arr[], int len, int x){
    if(len<0){
        return -1;
    }
    if(arr[0] == x){
        return len;
    }
    return firstIndex(arr+1,len-1,x);

}

int main(){
    int len, x;
    cin >> len;
    int *arr = new int[len];
    int counter=0;
    while(counter < len){
        cin >> arr[counter];
        counter++;
    }
    cin >> x;
    int result  = firstIndex(arr,len,x);
    if(result != -1){
        cout << len - result;
    } else{
        cout << -1;
    }
    cout << endl;
}