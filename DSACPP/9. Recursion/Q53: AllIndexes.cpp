/*
Problem Statement: All indexes of x
Problem Level: MEDIUM
Problem Description:
Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in an array (in increasing order).
Do this recursively. Indexing in the array starts from 0.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x

Output Format :
indexes where x is present in the array (separated by space)
*/
#include "iostream"
using namespace std;

int allIndex(int arr[], int len, int x, int counter){
    if(counter==len){
        return -1;
    }
    if(arr[counter] == x) {
        return counter;
    }
    counter++;
    return allIndex(arr,len,x,counter);
}

int main(){
    int len,x;
    cin >> len;
    int *arr = new int[len];
    for(int i = 0;i<len;i++){
        cin >> arr[i];
    }
    cin >> x;
    if(allIndex(arr,len,x,0) == -1){
        cout << -1;
    } else{
        int counter = 0;
        int result = allIndex(arr,len,x,counter);
        while(result != -1){
            cout << result<< " ";
            result++;
            result = allIndex(arr,len,x,result);
        }
    }
    cout << endl;

}