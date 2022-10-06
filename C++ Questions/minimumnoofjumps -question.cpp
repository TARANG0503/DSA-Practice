#include<iostream>
using namespace std;

void minimize(int arr[],int n)
{
    int ctr=0;
    for(int i=1;i<=n;i++)
    {
        i=i+arr[i];
        ctr++;
        if(i>=n)
            cout<<ctr;
        else
            continue;
    }
}

int main()
{
    int arr[]={1, 4, 3, 2, 6, 7};
    int n=sizeof(arr)/sizeof(int);
    minimize(arr,n);

    return 0;
}