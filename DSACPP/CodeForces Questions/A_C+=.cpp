/*Author : Manraj Singh */
#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;

    cin >> t;

    while (t--)
    {

        int a, b, c;
        cin >> a >> b >> c;
        int count = 0;

        while (max(a, b) <= c)
        {
            if (a < b)
            {

                a += b;
            }
            else
            {

                b += a;
            }

            count++;
        }

        cout << count << endl;
    }
    return 0;
}