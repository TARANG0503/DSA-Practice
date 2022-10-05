/*Author : Manraj Singh */
#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    if (n < m)
    {

        cout << "-1\n";
    }
    else
    {
        int moveofstep2 = n/2;
        int moveofstep1 = n- (2*moveofstep2);

        while ((moveofstep2+moveofstep1)%m != 0 )
        {
            moveofstep1++;
        }

        cout<<moveofstep2+moveofstep1<<endl;
         
        
    }

    return 0;
}