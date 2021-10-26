/*
Problem Statement: Binary Search (Recursive)
Problem Level: EASY
Problem Description:
Given an integer sorted array (sorted in increasing order) and an element x, find the x in given array using binary search. Return the index of x.
Return -1 if x is not present in the given array.
Note : If given array size is even, take first mid.
Input format :
Line 1 : Array size
Line 2 : Array elements (separated by space)
Line 3 : x (element to be searched)
 */
#include "iostream"
using namespace std;

int binarySearch(int arr[],int num, int low, int high){
    if(low>high){
        return -1;
    }
    int mid  = (low + high)/2;
    if(arr[mid] == num){
        return mid;
    } else if(arr[mid]>num){
        return binarySearch(arr,num,low, mid-1);
    } else{
        return binarySearch(arr,num,mid+1,high);
    }
}

int main(){
    int len;
    cin >> len;
    int *arr = new int[len];
    int counter = 0;
    while(counter<len){
        cin >> arr[counter];
        counter++;
    }
    int num;
    cin >> num;
    cout << binarySearch(arr,num,0,len-1)<<endl;
}