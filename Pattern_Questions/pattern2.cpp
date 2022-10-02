#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int i=1;
    while(i<=n)
    {
        int j=1;
        while(j<=n)
        {
            int k= n-j+1;   // if we want to print the 3 2 1 will use this formulal
            cout<<k<<" ";
            j=j+1;
        }
        cout<<" "<<endl;
        i=i+1;


    }
}