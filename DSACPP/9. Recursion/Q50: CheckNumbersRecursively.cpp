/*
 *Problem Statement: Check number recursively
Problem Level: EASY
Problem Description:
Given an array of length N and an integer x, you need to find if x is present in the array or not. Return true or false.
Do this recursively.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
'true' or 'false'
*/
#include "iostream"
using namespace std;

bool search(int arr[], int len,int num){
    if(len<0){
        return false;
    }
    if(arr[0]==num){
        return true;
    }
    return search(arr+1,len-1,num);
}

int main(){
    int len;
    int *arr = new int[len];
    int num;
    cin >> len;
    int counter= 0;
    while(counter<len){
        cin >> (arr[counter]);
        counter++;
    }
    cin >> num;
    if(search(arr,len,num)==0){
        cout << "Not Found"<<endl;
    } else{
        cout << "Found it"<<endl;
    }

}