#include<iostream>
using namespace std;

void insertion_sort(int arr[], int size)
{
    int i, j, k, el, pos;
    for(i=1; i<size; i++)
    {
        el = arr[i];
        if(el<arr[i-1])
        {
            for(j=0; j<=i; j++)
            {
                if(el<arr[j])
                {
                    pos = j;
                    for(k=i; k>j; k--)
                        arr[k] = arr[k-1];
                    break;
                }
            }
        }
        else
            continue;
        arr[pos] = el;
    }
}

int main()
{
    int arr[50], size, i;
    cout<<"Please enter number of elements in array: ";
    cin>>size;
    cout<<"Please enter "<<size<<" number of elements: ";
    for(i=0; i<size; i++)
        cin>>arr[i];
    
    insertion_sort(arr,size);
    
    cout<<"\nThe elements sorted in ascending order are:\n";
    for(i=0; i<size; i++)
        cout<<arr[i]<<"  ";
    cout<<endl;
    return 0;
}
