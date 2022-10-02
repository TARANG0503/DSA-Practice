#include<bits/stdc++.h>
using namespace std;
int countPrimes(int n) {
        if(n<2)
            return 0;
        bool arr[n+1];
        int i;
        
        for(i=1;i<=n;i++)
            arr[i]=true;
        arr[1]=false;
        for(i=2;i*i<=n;i++)
        {
            if(arr[i]==1)
            {
                for(int j=i*i;j<=n;j+=i)
                    arr[j]=false;
            }
        }
        int c=0;
        for(i=1;i<n;i++)
        {
            if(arr[i]==true){
                c++;}
        }
        return c;
        
    }
  int main()
  {
    int n;
    cin>>n;
    cout<<countPrimes(n);
  }