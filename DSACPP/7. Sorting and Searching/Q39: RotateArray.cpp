/*
 * Rotate an Array
 */
#include "iostream"
using namespace std;
void swap(int arr[], int i, int j){ // Swapping function
    int temp = arr[i];
    arr[i]= arr[j];
    arr[j] = temp;
}
void rotateArray(int arr[],int len){
    int counter = 1;
    int temp = arr[0];
    while(counter<len){
        swap(arr,counter,counter-1);
        counter++;
    }
    arr[len-1] = temp;
}
int main(){
    int len ;
    int arr[100];
    cin >> len;
    int counter = 0;
    int rotate;  // number of rotations
    while(counter < len){
        cin >> arr[counter];
        counter++;
    }
    cin >> rotate;
    counter = 0;
    while(counter<rotate){
        rotateArray(arr,len);
        counter++;
    }
    counter = 0;
    while(counter < len){
        cout << arr[counter]<<" ";
        counter++;
    }
    cout << endl;
}