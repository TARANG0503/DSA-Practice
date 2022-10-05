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
    li hc, hm, dc, dm, k, w, a, i = 0;
    cin >> hc >> dc >> hm >> dm >> k >> w >> a;
    while (i <= k)
    {
        li mxhc = hc + a * i, mxdc = dc + w * (k - i);

        if (mxhc / dm + (bool)(mxhc % dm) >= hm / mxdc + (bool)(hm % mxdc))
        {
            cout << "YES" << endl;
            return 0;
        }
        i++;
    }
    cout << "NO";
    cout << endl;

    // if((hm/(dc+w*k)+((hm%(dc+w*k))))>((hc+a*k)/dm)+(((hc+a*k)%dm)))
    // cout<<"NO"<<endl;
    // else cout<<"YES"<<endl;

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