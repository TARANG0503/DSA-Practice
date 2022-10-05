/*Author : Manraj Singh */
#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    string ans;
    ans.resize(0);

    for (int i = 0; i < s.size(); i++)
    {
        int n = (int)s[i] - '0';

        if (n == 9 && ans.size() == 0)
        {
            ans.push_back(n+'0');
            
        }
        else if (9 - n < n)
        {

            ans.push_back((9 - n)+'0');
        }
        else
        {

            ans.push_back(n+'0');
        }
    }

    if(ans.empty()){

        cout<<s<<endl;
    }
    else{

        cout<<ans<<endl;
    }

    return 0;
}