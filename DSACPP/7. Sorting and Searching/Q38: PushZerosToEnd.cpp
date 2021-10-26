/*
 * In an array Push Zeros to the end of the array
 */

#include "iostream"
using namespace std;
void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int main(){
    int len;
    int arr[100];
    cin >> len;
    int counter = 0;
    while(counter<len){
        cin >> arr[counter];
        counter++;
    }
    int i =0;
    int j = len-1;
    while(i<j){
        if(arr[i] == 0 && arr[j] == 0){
            j--;
        }else if(arr[i] ==0 && arr[j] != 0){
            swap(arr,i,j);
            i++;
        }else if(arr[i] != 0 && arr[j] == 0){
            j--;
        } else{
            i++;
        }
    }
    counter = 0;
    while(counter<len){
        cout << arr[counter]<<" ";
        counter++;
    }
    cout << endl;
}