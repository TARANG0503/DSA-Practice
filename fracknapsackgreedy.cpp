//============================================================================
// Name        : Assignment1.cpp
// Author      : Vaishnavi Dhadiwal – 33314
// Batch       : M11
// Description : Program to solve fractional knapsack
//		         problem using greedy approach
//============================================================================

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Items{
public:
	string s;
    	double weight;
	double profit;
	double ratio;
	void merge(Items[],int,int,int);
	void mergesort(Items[],int,int);
	void knapsack(Items[],int,int);
};
void Items::merge(Items arr[], int l, int mid, int r)
{
	 int n1=mid-l+1;
	 int n2=r-mid;

	 Items temp1[n1];
	 Items temp2[n2];

	 for(int i=0;i<n1;i++){
		 temp1[i]=arr[l+i];
	 }
	 for(int i=0;i<n2;i++){
			 temp2[i]=arr[mid+1+i];
	}
	 int i=0,j=0;
	 int k=l;
	 while(i<n1 && j<n2){
		 if(temp1[i].ratio>temp2[j].ratio){
			 arr[k]=temp1[i];
			 i++;
			 k++;
		 }
		 else{
			 arr[k]= temp2[j];
			 j++;
			
 k++;
		 }
	 }
	 while(i<n1){
		 arr[k]=temp1[i];
		 i++;
		 k++;
	 }
	 while(j<n2){
		arr[k]= temp2[j];
		j++;
		k++;
	 }
}
void Items::mergesort(Items arr[], int l, int r)
{
	if(l<r){
		int mid=(l+r)/2;
		mergesort(arr,l,mid);
		mergesort(arr,mid+1,r);

		merge(arr,l,mid,r);
	}
}
void Items::knapsack(Items items[],int capacity,int n){
	int bag_wt=capacity;
	double max_profit=0;
	double ratio_taken[n];
	int i=0;
	for(int i=0;i<n;i++)
		ratio_taken[i]=0;
	while(i<n && bag_wt!=0){
		if(items[i].weight<=bag_wt){
			ratio_taken[i]=1;
			max_profit+=items[i].profit*ratio_taken[i];
			bag_wt-=items[i].weight;
		}
		else{
			ratio_taken[i]=bag_wt/items[i].weight;
			max_profit+=items[i].profit * ratio_taken[i];
			bag_wt=0;
		}
		i++;
	}
	cout<<"\n\tANALYSING ITEMS FOR YOUR KNAPSACK..........\n\n";
	cout<<"\n\t***** ITEMS AVAILABLE IN STORE *****\n";
	cout<<"\n\tNAME | WEIGHT | VALUE | (p/w)RATIO\n";
	for(int i=0;i<n;i++){
		cout<<"\t"<<items[i].s<<"\t "<<items[i].weight<<"\t "<<items[i].profit<<"\t  "<<items[i].ratio<<"\n";
	}
	cout<<"\n\t***** ITEMS ADDED IN KNAPSACK *****\n";
	cout<<"\n\tNAME | WEIGHT ADDED | PROFIT GAINED | RATIO ADDED\n";
	for(int i=0;i<n;i++){
		cout<<"\t"<<items[i].s<<"\t     "<<setprecision(2)<<items[i].weight*ratio_taken[i]<<"\t 	   "<<items[i].profit*ratio_taken[i]<<"\t	    "<<ratio_taken[i]<<"\n";
	}
	cout<<fixed<<"\n\t**** Woah! You gained a total profit of Rs "<<max_profit;
}
int main() {
	int n,capacity;
	cout<<"\nHow many items? ";
	cin>>n;
	cout<<"\nCapacity of knapsack? ";
	cin>>capacity;

	Items items[n];

	cout<<"\nEnter name, profit and weight of each item\n";
	for(int i=0;i<n;i++){
		cin>>items[i].s>>items[i].profit>>items[i].weight;
		items[i].ratio=items[i].profit/items[i].weight;
	}
	Items().mergesort(items,0,n-1);
	Items().knapsack(items,capacity,n);
	return 0;
}

