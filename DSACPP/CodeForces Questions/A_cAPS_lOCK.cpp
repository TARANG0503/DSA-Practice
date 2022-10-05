/*Author : Manraj Singh */
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    bool l = 0;
    bool ss = 0;
    int i;

    for (i = 0; i < s.size(); i++)
    {
        if (i == 0 && 97 <= s[i] && s[i] <= 122)
        {
            ss = 1;
        }
        else
        {

            if (65 <= s[i] && s[i] <= 90)
            {

                l = 1;
            }
            else
            {
                // cout<<s[i]<<"is small\n";

                l = 0;
                break;
            }
        }
    }
    // cout<<"ss = "<<ss<<" l = "<<l<<endl;

    if (ss == 0 && l == 1)
    {
        for (int j = 0; j < s.size(); j++)
        {

            cout << char((int)s[j] + 32);
        }
    }
    else if (ss == 1 && l == 1)
    {
        for (int j = 0; j < s.size(); j++)
        {
            if (j == 0)
            {
                cout << char((int)s[j] - 32);
            }
            else
            {

                cout << char((int)s[j] + 32);
            }
        }
    }
    else if (ss == 1 && l == 0 && s.size() == 1)
    {
        // cout<<"3"<<endl;

        for (int j = 0; j < s.size(); j++)
        {

            cout << char((int)s[j] - 32);
        }
    }
    else
    {
        cout << s;
    }

    return 0;
}