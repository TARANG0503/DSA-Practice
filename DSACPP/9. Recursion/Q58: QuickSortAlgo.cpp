/*
 * Quick Sort Algo
 */
#include "iostream"
using namespace std;
void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int partation(int arr[], int si, int ei){
    int counter = 0;
    for(int i = si+1;i<=ei;i++){
        if(arr[si]>arr[i]){
            counter++;
        }
    }
    swap(arr,si,si+counter);
    int i = si;
    int j = ei;
    while(i<si+counter && si+counter<j){
        if(arr[i]>=arr[si+counter]){
            if(arr[j]<arr[si+counter]){
                swap(arr,i,j);
                i++;
            }
            j--;
        }else{
            if(arr[j]>=arr[si+counter]){
                j--;
            }
            i++;
        }
    }
    return si+counter;
}
void quickSort(int arr[], int si, int ei){ // si - Starting Index & ei - Ending Index
    if(si>=ei){
        return;
    }
    int c = partation(arr,si,ei);
    quickSort(arr,si,c-1);
    quickSort(arr,c+1,ei);
}

int main(){
    int len;
    cin >> len;
    int *arr = new int[len];
    int counter = 0;
    while(counter<len){
        cin >> arr[counter];
        counter++;
    }
    quickSort(arr,0,len-1);
    counter = 0;
    while(counter <len){
        cout << arr[counter] << " ";
        counter++;
    }
    delete [] arr;
}
