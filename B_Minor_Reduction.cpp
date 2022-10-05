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
    string s, tem = "";
    cin >> s;
    int indi = 0, t;
    char c;
    bool flag = 0;
    for (int i = s.length() - 2; i >= 0; i--)
    {
        if (s[i] + s[i + 1] -'0'> '9')
        {
            indi = i;
            int f = s[i] - '0' + s[i + 1] - '0';
            c = f % 10 + '0';
            f /= 10;
            tem.push_back(c);
            c = f % 10 + '0';
            f /= 10;
            tem.push_back(c);
            reverse(all(tem));
            flag = 1;
            // cout << "DONE" << endl<<tem<<endl;
            break;
        }
    }
    if (flag == 0)
    {
        c = s[0] + s[1] - '0';
        tem.push_back(c);
        indi = 0;
    }
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (i == indi)
        {
            for (int j = 0; j < tem.length(); j++)
            {
                ans.push_back(tem[j]);
            }
            i += 1;
            continue;
        }
        ans.push_back(s[i]);
    }
    cout << ans << endl;

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