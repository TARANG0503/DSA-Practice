/*Author : Manraj Singh */
#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    unordered_map<string, int> mapped;

    mapped["Tetrahedron"] = 4;
    mapped["Cube"] = 6;
    mapped["Octahedron"] = 8;
    mapped["Dodecahedron"] = 12;
    mapped["Icosahedron"] = 20;

    int n;
    cin >> n;

    long long int ans = 0;
    while (n--)
    {
        string s;
        cin >> s;

        ans += mapped[s];
    }

    cout << ans << endl;

    return 0;
}