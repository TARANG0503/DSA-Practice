/*
 *  M E R G E  | S O R T  | A L G O R I T H M  |
 */
#include "iostream"
using namespace std;

void merge(int arr[], int i1,int j1,int i2, int j2){
    int count = i1;
    int len = j2-i1 + 1;
    int *res = new int[len];
    int counter = 0;
    while(counter<len){
        if(arr[i1]>=arr[i2] && i2<=j2){
            res[counter] = arr[i2];
            i2++;
        }else {
            res[counter] = arr[i1];
            i1++;
        }
        counter++;
    }
    counter = 0;
    while(counter<len){
        arr[count] = res[counter];
        counter++;
        count++;
    }
    delete [] res;
}

void mergeSort(int arr[], int si, int ei){  // si - Starting Index , ei - Ending Index, mi
    if(si>=ei){
        return;
    }
    int mid = (si+ei)/2;
    mergeSort(arr, si, mid);
    mergeSort(arr,mid+1, ei);
    merge(arr,si,mid,mid+1,ei);

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
    mergeSort(arr,0,len-1);
    counter = 0;
    while(counter <len){
        cout << arr[counter] << " ";
        counter++;
    }
    delete [] arr;
}
