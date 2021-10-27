/*
Problem Statement: Rotate array
Problem Level: EASY
Problem Description:
You have been given a random integer array/list(ARR) of size N. Write a function that rotates the given array/list by D elements(towards the left).
Note:
Change in the input array/list itself. You don't need to return or print the elements.
 */
#include "iostream"
using namespace std;

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void reverse(int arr[], int startFrom, int to){
    while(startFrom<to){
        swap(arr,startFrom,to);
        startFrom++;
        to--;
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
    int rotateBy;
    cin >> rotateBy;
    rotateBy = rotateBy%len;
    reverse(arr,0,len-1);
    reverse(arr,0,len-rotateBy-1);
    reverse(arr,len-rotateBy,len-1);
    for(int i = 0;i<len;i++){
        cout << arr[i] << " ";
    }
    delete [] arr;
}
