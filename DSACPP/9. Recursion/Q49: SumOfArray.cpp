/*
Problem Statement: Sum of array (recursive)
Problem Level: EASY
Problem Description:
Given an array of length N, you need to find and return the sum of all elements of the array.
Do this recursively.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
*/
#include "iostream"
using namespace std;

int sumArray(int arr[], int len){
    if(len == 1){
        return arr[0];
    }
    return arr[0] + sumArray(arr+1,len-1);
}


int main(){
    int len;
    int arr[100];
    cin >> len;
    int counter=0;
    while (counter<len){
        cin >> arr[counter];
        counter++;
    }
    cout << sumArray(arr,len)<<endl;

}