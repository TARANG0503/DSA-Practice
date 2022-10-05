/*Author : Manraj Singh */
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, gap1, gap2;
    cin >> n >> gap1 >> gap2;

    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        vec.push_back(v);
    }

    // if (gap1 + gap2 + 1 > n)
    // {

    //     int smallest = 0;
    //     for (int i = 0; i < n; i++)
    //     {
    //         if (vec[smallest] > vec[i])
    //         {

    //             smallest = i;
    //         }
    //     }

    //     cout << smallest + 1;
    //     return 0;
    // }

    for (int i = 0; i < n; i++)
    {
        int smallest_g1 = INT_MAX;
        int smallest_g2 = INT_MAX;

        int smallest = i;
        int j;
        // cout << "i = " << vec[i] << endl;
        if (i - 1 >= 0)
        {

            for (int steps = gap1, j = i - 1; steps > 0 && j >= 0; steps--, j--)
            {
                if (smallest_g1 > vec[j])
                {

                    smallest_g1 = vec[j];
                }
            }
        }
        // cout << "b sm = " << smallest_g1 << endl;
        if (i+1 < n)
        {

            for (int steps = gap2, j = i + 1; steps > 0 && j < n; steps--, j++)
            {
                if (smallest_g2 > vec[j])
                {

                    smallest_g2 = vec[j];
                }
            }
            // cout << "a sm = " << smallest_g2 << endl;
        }

        if (smallest_g1 > vec[smallest] && smallest_g2 > vec[smallest])
        {

            cout << smallest + 1 << " ";
            break;
        }

        if (j == n)
        {
            cout << 0 << endl;
        }
    }

    return 0;
}