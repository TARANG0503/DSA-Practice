/*
 * Insertion Sort
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
    for(int i = 0;i<len;i++){
        counter = i+1;
        for(int j = i+1;j>=0;j--){
            if(arr[counter]<arr[j]){
                swap(arr,counter,j);
                counter = j;
            }
        }
    }
    counter = 0;
    while(counter<len){
        cout << arr[counter]<<" ";
        counter++;
    }
    cout << endl;
}