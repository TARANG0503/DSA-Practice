#include <iostream>
#include <math.h>
using namespace std;

// First Occurence check krna haaiii

int First(int arr[], int size, int key){
int start=0;
int ans=0;
int end= size-1;
int mid = (start + end)/2;
while(start<=end )
{

if(arr[mid]==key){

    ans=mid;
    end=mid-1;
}
if(key > arr[mid]){
start= mid + 1;
}
else{
    end= mid-1;
}

mid=(start+end)/2 ;   
  

}


return ans;

} \
int Second(int arr[], int size, int key){
int start=0;
int ans=0;
int end= size-1;
int mid = start + (end-start)/2;
while(start<=end )
{

if(arr[mid]==key){

    ans=mid;
    start=mid+1;
}
if(key > arr[mid]){
start= mid + 1;
}
else{
    end= mid-1;
}

mid = start + (end-start)/2;  
  

}


return ans;

}     

int main()

{ 
    int even[6]={1,2,3,3,3,5};
    int odd[5]={4,6,8,9,14};

    int first= First(even, 6, 3);
    int second= Second(even, 6, 3 );

    cout<<"Index of Fisrt Occurence is " << first <<endl;
    cout<<"Index of last Occurence is " << second <<endl;




}