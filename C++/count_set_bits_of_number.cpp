#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int count_set_bit(int n)
{
    int mask=1;
    int ans=0;
    while(mask<=n)
    {
        if(mask&n)
        {
            ans++;
        }
        mask=mask<<1;
    }
    return ans;
}
int main()
{
    cout<<"please enter the number:-";
    int n;
    cin>>n;
    int ans=count_set_bit(n);
    cout<<ans<<endl;

}
