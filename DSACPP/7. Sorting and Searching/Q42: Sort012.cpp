/*
 * Sort an array of 0s and 1s and 2s
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
        counter ++;
    }
    int i = 0;
    int j = len-1;
    int numberOfZeros =0;
    while(i<j){ // first sorting 0s
        if(arr[i] == 0 && arr[j] == 0){
            i++;
            numberOfZeros++;
        } else if(arr[i] == 0 && arr[j] != 0){
            i++;
            j--;
            numberOfZeros++;
        } else if(arr[i] != 0 && arr[j] == 0){
            swap(arr,i,j);
            i++;
            j--;
            numberOfZeros++;
        } else{
            j--;
        }
    }
    i = numberOfZeros;
    j = len-1;
    while(i<j){  // sorting 2s in the array
        if(arr[i] == 2 && arr[j] == 2){
            j--;
        }else if(arr[i] == 2 && arr[j] !=2){
            swap(arr,i,j);
            i++;
            j--;
        } else if(arr[i] != 2 && arr[j] ==2){
            i++;
            j--;
        } else{
            i++;
        }
    }
    counter = 0;
    while(counter<len){
        cout << arr[counter]<<" ";
        counter ++;
    }
    cout << endl;
}