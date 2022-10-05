/*Author : Manraj Singh */
#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> oe(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];

        if (v[i] > 0)
        {

            if (v[i] % 2 != 0)
            {

                oe[i] = 1;
            }
        }
        else if(v[i]< 0)
        {
            if ((-1 * v[i]) % 2 != 0)
            {

                oe[i] = 1;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        v[i] = v[i] / 2;
        sum += v[i];
    }

    cout << sum << endl;
    if (sum < 0)
    {
        int i = 0;
        while (sum != 0)
        {
            if (oe[i])
            {
                v[i] += 1;
                // cout<<"added 1, sum = "<<sum<<endl;
                sum += 1;
            }

            i = (i + 1) % n;
            // cout<<"i = "<<i<<endl;
        }
    }
    else if (sum > 0)
    {

        int i = 0;
        while (sum != 0)
        {
            if (oe[i])
            {
                // cout<<"sub 1, sum = "<<sum<<endl;
                v[i] -= 1;
                sum -= 1;
            }

            i = (i + 1) % n;
            // cout<<"i = "<<i<<endl;
        }
    }
    // cout << sum << endl;

    // int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
        // sum += 0;
    }

    return 0;
}