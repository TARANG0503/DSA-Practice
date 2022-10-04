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
    li w,h;
    cin>>w>>h;
    li a1,b1,a2,b2,c1,d1,c2,d2;
    li n1,f=1;
    cin>>n1;
    for (int i = 0; i < n1; i++)
    {
    
        if(f){
            f=0;
            cin>>a1;
            continue;
        }
        cin>>b1;
    }
    cin>>n1;
    f=1;
    for (int i = 0; i < n1; i++)
    {
        if(f){
            f=0;
            cin>>a2;
            continue;
        }
        cin>>b2;
    }
    cin>>n1;
    f=1;
    for (int i = 0; i < n1; i++)
    {
        if(f){
            f=0;
            cin>>c1;
            continue;
        }
        cin>>d1;
    }
    cin>>n1;
    f=1;
    for (int i = 0; i < n1; i++)
    {
        if(f){
            f=0;
            cin>>c2;
            continue;
        }
        cin>>d2;
    }
    li A1=(b1-a1)*h;
    li A2=(b2-a2)*h;
    li A3=(d1-c1)*w;
    li A4=(d2-c2)*w;
    cout<<max(max(A1,A2),max(A3,A4))<<endl;

    

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