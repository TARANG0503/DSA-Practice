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
    int n, m;
    cin >> n >> m;
    vector<string> direc;
    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        direc.push_back(t);
    }
    string s;
    cin >> s;
    vector<tuple<int, int, int, string>> vpis2, vpis3;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {

            if (j < m - 2)
            {
                string s3 = direc[i].substr(j, 3);
                vpis3.push_back({j + 1 , j + 3, i + 1 ,s3});
            }
            string s2 = direc[i].substr(j, 2);
                vpis2.push_back({j + 1 , j +2 , i + 1 ,s2});
        }
    }
    for (int itr = 0; itr < m; itr++)
    {
        
    }
    
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