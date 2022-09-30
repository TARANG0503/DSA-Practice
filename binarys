#include <iostream>
using namespace std;
int binarysearch(int arr[],int l,int end,int x)
{
   int mid;
   if(end>=l)
    {
        mid=l+(end-l)/2;
        if(arr[mid]==x)
        return 1;
        else if(x>arr[mid])
        {
            return binarysearch(arr,mid+1,end,x);
        }
        else 
        {
            return binarysearch(arr,l,mid-1,x);
        }
    }
    return 0;
}

int main() {
  int i,j,k,l,n,arr[10000],x;
  cin>>n;
  for(i=0;i<n;i++)
  {
      cin>>arr[i];
  }
  cin>>x;
  k=binarysearch(arr,0,n-1,x);
  if(k==1)
  {
      cout<<"found!!";
  }
  else
  {
      cout<<"not found!!";
  }
  
	return 0;
}
