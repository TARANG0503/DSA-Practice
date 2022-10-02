#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=4e5+5;
ll a[N],seg[4*N];
void build(ll node,ll st,ll end)
{
 if(st==end)
 {
    seg[node]=a[st];
    return;
 }
 ll mid=st+(end-st)/2;
 build(2*node+1,st,mid);
 build(2*node+2,mid+1,end);
 seg[node]=min(seg[2*node+1],seg[2*node+2]);
}
ll query(ll node,ll st,ll end,ll l,ll r)
{
   if(st>=l and end<=r)
   {
    return seg[node];
   }
   if(end<l || st>r)
   {
    return 1e18;
   }
   ll mid=st+(end-st)/2;
   ll left=query(2*node+1,st,mid,l,r);
   ll right=query(2*node+2,mid+1,end,l,r);
   return min(left,right);
}
void update(ll node,ll st,ll end,ll idx,ll val)
{
    if(st==end)
    {
        a[node]=val;
        seg[node]=val;
        return;
    }
    ll mid=st+(end-st)/2;
    if(idx<=mid)
    {
   update(2*node+1,st,mid,idx,val);
    }
    else
    { 
    update(2*node+2,mid+1,end,idx,val);
    }
    seg[node]=min(seg[2*node+1],seg[2*node+2]);
}
int main()
{
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    build(0,0,n-1);
    while(m--)
    {
        ll type;
        cin>>type;
        if(type==1)
        {
            ll i,v;
            cin>>i>>v;
            update(0,0,n-1,i,v);

        }
        else
        {
            ll l,r;
            cin>>l>>r;
            cout<<query(0,0,n-1,l,r-1)<<endl;
        }
    }
    return 0;
}