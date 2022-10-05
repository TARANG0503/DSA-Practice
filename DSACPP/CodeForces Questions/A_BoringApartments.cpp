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

        string s;
        cin >> s;

        int n = stoi(s);

        int destination = n % 10;

        int count = s.size();


        int i = 1;

        int sum = 0;

        while (i <= destination - 1)
        {
            sum += 10;
            i++;
        }

        int num = 1;
        sum += 1;
        count--;

        while (count--)
        {
            num++;
            sum +=num;
            
        }

        cout<<sum<<endl;
    }

    return 0;
}