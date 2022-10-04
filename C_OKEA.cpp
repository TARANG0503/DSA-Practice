//🎃🎃🎃😎😎😁🤓☣☣☣☣☣dark_coder☣☣☣☣☣🤓😁😎😎🎃🎃🎃
#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define li long long int
#define pi pair<int, int>
#define lcm(a, b) (a / __gcd(a, b) * b)
const long long INF = 1e9 + 7;
const long long MOD = 998244353;
long long power(long long a, long long b)
{
    long ans = 1;
    while (b > 0)
    {
        if (b & 1)
            ans = (ans * a) % INF;
        a = (a * a) % INF;
        b >>= 1;
    }
    return ans % INF;
}
int solve()
{
    int r,c;
    cin>>r>>c;
    if(c!=1&&r%2){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    int a[r][c],sm=1;
    for (int i = 0; i < r; i++)
    {
        sm=i+1;
        for (int j = 0; j < c; j++)
        {
            cout<<sm<<' ';
            sm+=r;
        }
        cout<<endl;
    }
    
    
    
    return 0;
}
int main()
{
    IOS int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}