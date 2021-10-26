/*
 * Sort 0 1 in an array
 * with 0 in front of the array and 1 at the end.
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
    cin >> len;
    int arr[100];
    int counter = 0;
    while(counter<len){
        cin >> arr[counter];
        counter++;
    }
    int i = 0;
    int j = len-1;
    while(i<j){
        if(arr[i] == 1 && arr[j] == 1){
            j--;
        }else if(arr[i] == 0 && arr[j] == 0){
            i++;
        }else if(arr[i]  == 1){
            swap(arr,i,j);
            i++;
            j--;
        }else if(arr[j] == 1){
            j--;
        }
    }
    counter = 0;
    while(counter<len){
        cout << arr[counter]<<" ";
        counter++;
    }
}