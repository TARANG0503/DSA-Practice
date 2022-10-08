#include <iostream>
using namespace std;

int main(){


// to insert an element into an array

int arr[30],i,elem,index,tot;


cout<<"enter the size of your array: ";
cin>>tot;

cout<<"enter "<<tot<<" array element: ";
for(i=0;i<tot;i++){
    cin>>arr[i];
    
}
    cout<<"\n enter element to insert: ";
    cin>>elem;
    
    cout<<"\n enter position you want to insert element into: ";
    cin>>index;

for(i = tot; i>=index;i--){
    arr[i] = arr[i-1];
}
    arr[i] = elem;
    tot++;


for(i=0;i<tot;i++){
    cout<<arr[i]<<endl;
}


}
