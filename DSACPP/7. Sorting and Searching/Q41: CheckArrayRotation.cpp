/*
 * Check Array Rotation
 */
#include "iostream"
using namespace std;
int main(){
    int len;
    int arr[100];
    cin >> len;
    int counter = 0;
    while(counter<len){
        cin >> arr[counter];
        counter++;
    }
    int i = 1;
    while(i<len){
        if(arr[i]>arr[i-1]){
            i++;
        }else{
            break;
        }
    }
    if(i==len){
        cout << 0;
    }else{
        cout << i;
    }
    cout << endl;
}