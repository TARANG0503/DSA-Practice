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
    int x = 0;
    while (n--)
    {

        string s;
        cin >> s;
        if (s == "--X" || s == "X--")
        {

            x--;
        }
        else
        {

            x++;
        }
    }

    cout << x << "\n";

    return 0;
}