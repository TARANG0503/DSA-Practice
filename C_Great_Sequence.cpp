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
#define ld long double
const long long INF = 1e9 + 7;
const long long MOD = 998244353;
#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif
void _print(int t)
{
    cerr << t;
}
void _print(ld t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
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
int hi = 0;
int solve()
{
    // cout<<hi++<<endl;
    li n, k;
    cin >> n >> k;
    multiset<li> s;
    for (li i = 0; i < n; i++)
    {
        li t;
        cin >> t;
        s.insert(t);
    }
    li cnt = 0;
    while (n > 0)
    {
        auto it = s.begin();
        li i = *it;
        auto it2 = s.find(i * k);
        // debug(i)
        // debug(s)
        if (it2 != s.end())
        {
            s.erase(it2);
            s.erase(it);
            n -= 2;
        }
        else
        {
            cnt++;
            s.erase(it);
            n--;
        }
    }

    cout
        << cnt << endl;

    return 0;
}
int main()
{
    IOS li t;
    cin >> t;
    while (t--)
    {
        // cout<<t+1<<endl;
        solve();
    }

    return 0;
}