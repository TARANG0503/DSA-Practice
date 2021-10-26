/*
 * Selection Sort Algorithm
 */

#include "iostream"
using namespace std;
void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int main(){
    int arr[100];
    int len;
    cin >> len;
    int counter = 0;
    while(counter<len){
        cin>>arr[counter];
        counter++;
    }
    for(int i = 0; i < len-1;i++){
        int min = i;
        for(int j = i+1;j<len;j++){
            if(arr[min] > arr[j]){
                min  = j;
            }
        }
        swap(arr,min,i);
    }
    counter = 0;
    while(counter<len){
        cout<<arr[counter]<< " ";
        counter++;
    }
    cout << endl;
}