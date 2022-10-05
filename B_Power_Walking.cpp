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
    int n;
    cin >> n;
    vector<int> v;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        m[t]++;
    }
    int s = 0;
    for (auto &i : m)
    {
        s++;
    }
    int s1 = s, cnt = 0;
    while (s)
    {
        v.push_back(s1);
        s--;
        cnt++;
    }

    while (cnt < n)
    {
        cnt++;
        v.push_back(cnt);
    }
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