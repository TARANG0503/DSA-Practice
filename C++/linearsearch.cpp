#include <bits/stdc++.h>
using namespace std;

int linearsearch(int *arr, int n, int x) {
    if(arr[i] == x){
        return i;
    }
    else{
        return -1;
    }
}



int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int *arr = new int[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int num;
        cin>>num;
        cout<< linearsearch(arr, n, num)<< endl;

    }
    return 0;
}