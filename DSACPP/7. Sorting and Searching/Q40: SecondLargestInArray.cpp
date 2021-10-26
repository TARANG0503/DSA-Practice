/*
 * Second Largest in array
 */
#include "iostream"
using namespace std;
int main(){
    int len;
    int arr[100];
    int counter = 0;
    cin >> len;
    while(counter<len){
        cin >> arr[counter];
        counter++;
    }
    int largest = arr[0];
    int secondLargest = arr[1];
    counter = 1;
    while(counter<len){
        if(arr[counter]>largest){
            secondLargest = largest;
            largest = arr[counter];
        } else if(arr[counter] > secondLargest){
            secondLargest = arr[counter];
        }
        counter++;
    }
    cout << secondLargest << endl;
}