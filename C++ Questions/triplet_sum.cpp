#include <iostream>
#include <math.h>
using namespace std;

int main()

{ 
int arr[]={1,2,3,4,5,6,7};
int s=8;
for (int i=0; i<7;i++){
 for (int j = i+1; i < 7; j++)
 {
    for (int k = j+1; i < 7; k++)
    {
        if(arr[i]+arr[j]+arr[k]==s){
            cout<<  arr[i] << " " <<  arr[j] << " " <<  arr[k]  << endl;
        }
        
    }
    
 }
 

}







}