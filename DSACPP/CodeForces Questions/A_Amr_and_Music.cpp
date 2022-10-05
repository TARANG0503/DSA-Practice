/*Author : Manraj Singh */
#include <bits/stdc++.h>
using namespace std;

int fun(pair<int, int> &a, pair<int, int> &b)
{

    if (a.first > b.first)
    {
        return 1;
    }
    return 0;
}
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> v;
    vector<pair<int, int>> ans;

    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        v.push_back({m, i});
    }

    sort(v.begin(), v.end());

    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i].first << " " << v[i].second << endl;
    // }

    int i = 0;
    while (i < n)
    {
        if (k >= v[i].first)
        {
            k -= v[i].first;
            // cout<<"k = "<<k<<endl;
            // cout<<"added : "<<v[i].second<<endl;
            ans.push_back(v[i]);
        }
        i++;
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].second + 1 << " ";
    }

    return 0;
}