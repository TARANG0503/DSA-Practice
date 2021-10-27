#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

//#pragma GCC optimize('O2') 
#define ll long long 
#define vll vector<ll>
#define vl vector<int>
#define tin tuple<ll,ll,ll>
#define mll map<ll,ll>
#define pi pair<ll,ll>
#define vp vector<pi>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define mt make_tuple
#define all(x) (x).begin(),(x).end()
#define rall(x) x.rbegin(), x.rend()
#define watch(x) cout << (#x) << ' is ' << (x) << endl
#define f(i,x,z) for(ll i=x;i<z;i++)
#define rf(i,x,z) for(ll i=x-1;i>=z;i--)
#define deb(x) cout<<'DEBUG------> '<<x<<endl
#define srt(v) sort(v.begin(), v.end())
#define rsrt(v) sort(v.rbegin(), v.rend())
#define clr(x) memset(x, 0, sizeof(x)) 
#define fa(i,vect) for(auto i : vect)
#define fr(i,vect) for(VI :: reverse_iterator i = vect.rbegin(); i != vect.rend(); i++)
#define mod 1000000007
//  for (auto &a : v)
//cin >> a;
//for (auto me : m) {
//std::vector<ll>::iterator it; 
//it = std::find (v.begin(), v.end(), ser);
//if (it != v.end())
# define INF 0x3f3f3f3f 
////////////////////////////////////////////////////////////////////////////////////////////

ll power(ll base,ll por)
{
ll res=1;
while(por>1){
if(por%2==1)
{
res*=base;
por--;
}
por/=2;
base*=base;
}
res*=base;
return res;
}
vector<ll> d,v;
void difference()
{
    ll n=v.size();
    f(i,0,n)
    {
        if(i==0)
        {
            d.pb(v[i]);
        }
        else
        {
            d.pb(v[i]-v[i-1]);
        }
        
    }
    d.pb(0);
}
void update(ll l, ll r, ll change)
{
    d[l]+=change;
    d[r+1]-=change;
}
void finalset()
{
    ll n=v.size();
    f(i,0,n)
    {
        if(i==0)
        {
            v[i]=d[i];
        }
        else
        {
            v[i]=d[i]+v[i-1];
        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////
int main()
{
//   freopen('a.txt', 'r', stdin); freopen('a_out.txt', 'w', stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t,n;
    cin>>t;                                   //basic input
    ll a,co=0,c=0,d=0,b=0,k;
    
    f(i,0,t)
    {
        cin>>a;
        v.pb(a);
    }
    difference();
    cin>>n;                       //update questions
    f(i,0,n)
    {
        ll initial,change,end;
        cin>>initial>>end>>change;
        update(initial,end,change);
    }
    finalset();                  // final update;
    f(i,0,t)
    {
        cout<<v[i]<<" ";
    }

   return 0;
}