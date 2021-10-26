/*
Problem Statement: Check Array Rotation
Problem Level: EASY
Problem Description:
You have been given an integer array/list(ARR) of size N. It has been sorted(in increasing order) and then rotated by some number 'K' in the clockwise direction.
Your task is to write a function that returns the value of 'K', that means, the index from which the array/list has been rotated.
*/
#include "iostream"
using namespace std;
int main(){
    int len;
    cin >> len;
    int *arr = new int[len];
    int counter = 0;
    while (counter< len){
        cin >>arr[counter];
        counter++;
    }
    int i =0;
    int j =i+1;
    while(j<len&&arr[i]<arr[j]){
        i++;
        j++;
    }
    if(j!=len){
        cout << j << endl;
    }else{
        cout <<0<<endl;
    }



    delete [] arr;
}