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
    int n, a, b;
    cin >> n >> a >> b;
    int i = n, j = 0;
    vector<int> v;
    v.push_back(a);
    for (int i = n; v.size() <= n / 2; i--)
    {
        
        if (i == a || i == b)
            continue;
        v.push_back(i);
    }

    v.push_back(b);
    for (int i = 1;  v.size() <= n; i++)
    {
        if (i == a || i == b)
            continue;
        v.push_back(i);
    }

    int mn = INT32_MAX, mx = -1;
    for (int i = 0; i < n / 2; i++)
    {
        mn = min(v[i], mn);
    }
    for (int i = n / 2; i < n; i++)
    {
        mx = max(v[i], mx);
    }
    // if (mx != b || mn != a)
    // {
    //     cout << -1 << endl;
    //     return 0;
    // }
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << ' ';
    }

    cout << endl;

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