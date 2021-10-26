/*
 * Merging Two Sorted Arrays
 */
#include "iostream"
using namespace std;
int main(){
    int len1;
    int counter = 0;
    int len2;
    int arr2[100];
    int arr1[100];
    cin>> len1;
    while(counter<len1){
        cin >> arr1[counter]; // Input the first array
        counter++;
    }
    counter = 0;
    cin >> len2;
    while (counter<len2){
        cin >> arr2[counter]; // Input the second array
        counter++;
    }
    int i = 0;
    int j = 0;
    int arr[100];
    counter =0;
    while(i<len1 || j<len2){
        if(arr1[i]<arr2[j] && i<len1){
            arr[counter] = arr1[i]; // Merging both sorted array
            i++;
        }else{
            arr[counter] = arr2[j];
            j++;
        }
        counter++;
    }

    counter = 0;
    while(counter<len1+len2){
        cout <<arr[counter]<<  " "; // Printing the merger sorted array
        counter++;
    }
    cout << endl;
}