#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int i=0;
    while(i<t)
    {
     
    int n;
    cin>>n;
    string A[n];
    for(int i=0;i<n;i++)
      {
        cin>>A[i];
      }
      int add=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]=="0")
        {
            bool t=true;
            int min;
            for(int j=0;j<n&&A[j]!="0";j++)
            {
                if(t)
                {
                    min=abs(j-i);
                    t=false;
                }
                cout<<j;
                if(min>abs(j-i))
                {
                    min=abs(j-i);
                    cout<<min<<"ff";
                }
            }
            add=add+min;
        }
    }
    cout<<"case # "<<i+1<<": "<<add;
    i++;
    }
}
