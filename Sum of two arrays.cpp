#include<iostream>
using namespace std;

int main(){
    int n1, n2;
    cin>>n1;
    int* a1 = new int[n1];
    for(int i = 0 ; i < n1; i++){
        cin>>a1[i];
    }
    
    cin>>n2;
    int* a2 = new int[n2];
    for(int i = 0 ; i < n2; i++){
        cin>>a2[i];
    }
    
    int carry=0;
   
int m=max(n1,n2);
 int* sum=new int[m];

    int i=n1-1;
    int j=n2-1;
    int k=m-1;
    int d;
    while(k>=0)
    {
        d=carry;
        if(i>=0)
        {
            d=d+a1[i];
        }
     if(j>=0)
        {
            d=d+a2[j];
        }
        int q=d/10;
        int r=d%10;
        carry=q;
        sum[k]=r;
    
        i--;
        j--;
        k--;
    }
    if(carry!=0)
    {
        cout<<carry<<endl;
    }
    for(int x=0;x<m;x++)
    {
        cout<<sum[x]<<endl;
    }
 
    
    
}
