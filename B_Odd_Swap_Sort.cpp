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

bool ck(vector<int> o, vector<int> os, vector<int> e, vector<int> es)
{
    for (int i = 0; i < os.size(); i++)
    {
        if (o[i] != os[i])
        {
            // cout << os[i]<<' '<<o[i]<<' ';
            return 0;
            
        }
    }
    for (int i = 0; i < es.size(); i++)
    {
        if (e[i] != es[i])
        {
            // cout << es[i]<<' '<<e[i]<<' ';
            return 0;
            
        }
    }
    return 1;
}

bool allsame(vector<int> v)
{
    if (v.size() <= 1)
        return 1;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] != v[i - 1])
            return 0;
    }
    return 1;
}
bool allxor(vector<int> v)
{
    for (int i = 1; i < v.size(); i++)
        if (v[i] % 2 != v[i - 1] % 2)
            return 0;
    return 1;
}
int solve()
{
    int n;
    cin >> n;
    vector<int> v(n), odd, even, odds, evens;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i]%2)
            odd.push_back(v[i]);
        else
            even.push_back(v[i]);
    }
    odds = odd;
    evens = even;
    sort(all(odds));
    sort(all(evens));
    if (allsame(v))
    {
        cout << "Yes\n";
        return 0;
    }
    auto srt=v;
    sort(all(srt));
    if(srt==v){
        cout<<"YES\n";
        return 0;
    }
    if (allxor(v))
    {
        cout << "No\n";
        return 0;
    }

    if (even!=evens||odd!=odds)
    {
        cout << "NO\n";
        return 0;
    }
    cout << "Yes\n";

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