
#include<iostream>

using namespace std;

int main()
{
    int n,i,flag,num;

    cout<<"Enter the size of the array : ";
    cin>>n;
    int a[n];                            //creating array of size n

    cout<<"Enter array elements : ";
    for(i=0;i<n;i++)
        cin>>a[i];

    cout<<"Enter the element to be searched : ";
    cin>>num;                                             //inputting the number to be searched

    for(i=0;i<n;i++)                                       //using linear search technique
    {
        if(num==a[i])
        {
            flag=1;
            break;
        }
    }

    if(flag==1)
        cout<<endl<<num<<" found successfully"<<endl;
    else
        cout<<endl<<num<<" not found "<<endl;
    return 0;
}
