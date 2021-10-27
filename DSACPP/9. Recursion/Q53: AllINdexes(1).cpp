/*
 * Second Way for question 53
 */
#include "iostream"
using namespace std;

void allIndexes(int arr[], int len, int x, int index = 0, bool printed = false){
    if(index==len && printed){
        cout << endl;
        return;
    } else if(index == len){
        cout<< -1<<endl;
        return;
    }
    if(arr[index] == x){
        cout << index<< " ";
        printed = true;
    }
    index++;
    allIndexes(arr,len,x,index,printed);
}

int main(){
    int len,x;
    cin >> len;
    int *arr = new int[len];
    for(int i = 0;i<len;i++){
        cin >> arr[i];
    }
    cin >> x;
    allIndexes(arr,len,x);

}