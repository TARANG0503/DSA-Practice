//
// Binary Search Algorithm
//

#include "iostream"
using namespace std;

int binarySearch(int arr[],int len, int num){
    int low = 0;
    int high = len-1;
    int mid;
    while(low < high){
        mid = (low+high)/2;
        if(arr[low] == num){
            return low;
        } else if(arr[high] == num){
            return high;
        } else if(arr[mid] == num){
            return mid;
        } else if(num > arr[mid]){
            low = mid+1;
        } else{
            high  = mid-1;
        }
    }
    return -1;
}
int main(){
    int len;
    cin >> len;
    int arr[100];
    int counter = 0;
    int num;
    while(counter<len){
        cin >> arr[counter];
        counter++;
    }
    cin >> num;
    cout<<binarySearch(arr,len,num)<<endl;
}