#include<iostream>
using namespace std;
int binarysearch(int A[], int f, int l, int x)
{
	if(l>=f)
	{
		int m=(f+l)/2;
		if(A[m]==x)
		{
			return m;
		}
		if(A[m]>x)
		{
			binarysearch(A, 0, m, x);
		}
		if(A[m]<x)
		{
			binarysearch(A, m+1, l, x);
		}
	}
      return -1;
}
int main()
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int x=10;
	int n=sizeof(arr)/sizeof(arr[0]);
	int t=binarysearch(arr, 0, n-1, x);
	if(t==-1)
	{
		int k;
		cout<<"Enter value of k: ";
		cin>>k;
		for(int i=n;i>=t;i--)
		{
		   arr[i+1]=arr[i];
		}
		arr[k]=x;
	}
	else
	{
		for(int i=t;i<n;i++)
		{
			arr[i]=arr[i+1];
		}
	}
}
