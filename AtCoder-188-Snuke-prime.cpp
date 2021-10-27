#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

#define ll long long 
#define all(x) (x).begin(),(x).end()
#define vll vector<ll>
#define vl vector<ll>
#define pi pair<ll,ll>
#define vp vector<pi>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rall(x) x.rbegin(), x.rend()
#define watch(x) cout << (#x) << ' is ' << (x) << endl
#define f(i,x,z) for(ll i=x;i<z;i++)
#define deb(x) cout<<'DEBUG------> '<<x<<endl
#define srt(v) sort(v.begin(), v.end())
#define clr(x) memset(x, 0, sizeof(x)) 
#define mll map<ll,ll>
#define mod 1000000007
//  for (auto &a : v)
//cin >> a;
//for (auto me : m) {
//std::vector<ll>::iterator it; 
//it = std::find (v.begin(), v.end(), ser);
//if (it != v.end())

int main()
{
//   freopen('input.txt', 'r', stdin);
//   freopen('output.txt', 'w', stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t,n;
    cin>>t>>n;
    ll a,b,c,co=0;
    vector<pair<ll,ll>> v;
    f(i,0,t)
    {
        cin>>a>>b>>c;
        v.pb(mp(a-1,c));
        v.pb(mp(b,-c));
    }
    srt(v);
    ll ans = 0, fee = 0, te = 0;
    for(auto x : v){
        if(x.fi != te){
            ans += min(n, fee) * (x.fi - te);
            te = x.fi;
        }
        fee += x.se;
    }
    cout<<ans;
   return 0;
}