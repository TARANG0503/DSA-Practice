/*
Problem Statement: Array Intersection
Problem Level: MEDIUM
Problem Description:
You have been given two integer arrays/list(ARR1 and ARR2) of size N and M, respectively.
You need to print their intersection; An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words, when there is a common value that exists in both the arrays/lists.
Note :
Input arrays/lists can contain duplicate elements.
The intersection elements printed would be in the order they appear in the first sorted array/list(ARR1).
*/
#include "iostream"
#include <bits/stdc++.h>
using namespace std;
void input(int arr[], int len){
    int counter = 0;
    while (counter<len){
        cin >> arr[counter];
        counter++;
    }
}
int main(){
    int len1, len2; // length of both arrays

    cin >> len1;
    int *arr1 = new int[len1];          // inputting first array
    input(arr1,len1);

    cin >> len2;
    int *arr2 = new int[len2];
    input(arr2,len2);                   // inputting second array

    sort(arr1, arr1+len1);         // Sorting first array

    sort(arr2, arr2+len2);         // sorting second array

    int counter = 0;
    int i = 0,j=0;
    while(i<len1 && j<len2){
        if(arr1[i] == arr2[j]){
            cout << arr1[i] << " ";
            i++;
            j++;
        }
        else if(arr1[i]>arr2[j]){
            j++;
        }else{
            i++;
        }
    }

}