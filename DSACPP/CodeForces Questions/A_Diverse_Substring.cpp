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
    string s;
    cin >> s;

    bool ans = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            ans = 1;
            map<char, int> mp;
            int n_by_2 = (j - i + 1) / 2;
            // cout<<"n\\2 = "<<n_by_2<<endl;
            for (int k = i; k <= j; k++)
            {
                mp[s[k]]++;
                
        
            for (int k = i; k <= j; k++)
            {
                if (mp[s[k]] > n_by_2)
                {
                    ans = 0;
                    break;
                }
            }

            if (ans && (j != i))
            {
                cout << "YES\n";
               // cout<<"i = "<<i<<" j = "<<j<<endl;
                for (int k = i; k <= j; k++)
                {
                    cout << s[k];
                }

                break;
            }
            else{
                ans = 0;
            }
        }

        if(ans){

            break;
        }
    }

    if(!ans){

        cout<<"NO\n";
    }

   

    return 0;
}