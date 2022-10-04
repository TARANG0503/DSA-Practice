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
bool ck(li a, li b)
{
    if ((a == 0 && b % 2 == 1) || (b == 0 && a % 2 == 1) || (a == 1 && b == 1))
    {
        return 1;
    }
    return 0;
}
int solve()
{
    li n;
    cin >> n;
    vector<li> v;
    for (li i = 0; i < n; i++)
    {
        li t;
        cin >> t;
        v.push_back(t);
    }
    if (n <= 4)
    {
        if (n == 4)
        {
            if (ck(v[1], v[2]))
                cout << -1 << endl;
            else
                cout << (v[1] + 1) / 2 + (v[2] + 1) / 2 << endl;
        }
        else if (n == 3)
        {
            if (v[1] % 2)
                cout << -1 << endl;
            else
                cout << v[1] / 2 << endl;
        }
        return 0;
    }

    li one = 0, evn = 0, sum = 0,o=0;
    for (li i = 1; i < n - 1; i++)
    {

        if (v[i] == 1)
        {
            one++;o++;
        }
        else
        {

            if (v[i] % 2)
            {
                one++;
                sum += v[i] / 2;
            }
            else
                sum += v[i] / 2;
        }
    }
    if (sum==0)
        cout << -1;
    else
        cout << sum + one;
    cout << endl;
//// cout << (sum + odd) / 2 << endl;
    return 0;
}
int main()
{
    IOS li t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}