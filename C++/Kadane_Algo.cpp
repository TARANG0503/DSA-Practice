//Kadane Algo can be stated as - Given an integer array, find a contiguous subarray within it that has the largest sum. 


#include<iostream>
#include<bits/stdc++.h>

#define vi vector<int>
#define vs vector<string>
#define vc vector<char>
#define vvi vector<vi>
#define pii pair<int,int>
#define rep(i,n) for(int i=0;i<n;i++)
#define repi(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second

using namespace std;
int maximum_subarray(int ar[],int n){
	int global_max=INT_MIN;
	int current_max=0;
	repi(i,1,n){
		current_max+=ar[i];
		current_max=max(ar[i],current_max);
		global_max=max(global_max,current_max);
	}
	return global_max;
}
int main(){
	int n;
	cin>>n;
	int ar[n];
	rep(i,n){
		cin>>ar[i];
	}
	cout<<"Maximum subarray sum is "<<maximum_subarray(ar,n);
}

