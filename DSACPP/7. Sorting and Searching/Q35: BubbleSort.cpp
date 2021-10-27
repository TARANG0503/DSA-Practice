/*
 * Bubble Sorting Algorithm
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
    for(int i = 0; i<len-1;i++){
        for(int j = 0;j<len-1- i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr,j,j+1);
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