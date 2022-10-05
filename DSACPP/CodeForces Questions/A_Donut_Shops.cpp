/*Author : Manraj Singh */
#include <bits/stdc++.h>
using namespace std;

#define lld long long int
lld a, b, c;

lld ok1(lld mid)
{

    lld costa = a * mid;
    lld costb = (mid % b == 0 && mid / b != 0) ? (mid / b) * c : ((mid / b) + 1) * c;

    if (costa >= costb)
    {

        return 1;
    }
    else
    {

        return 2;
    }
}

lld ok2(lld mid)
{

    lld costa = a * mid;
    lld costb = (mid % b == 0 && mid / b != 0) ? (mid / b) * c : ((mid / b) + 1) * c;

    if (costa > costb)
    {

        return 1;
    }
    else
    {

        return 2;
    }
}
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        cin >> a >> b >> c;

       if(a < c){

           cout<<1<<" ";
       }
       else{

           cout<<"-1 ";
       }
       if(c < a*b){

           cout<<b<<endl;
       }
       else{

           cout<<"-1\n";
       }



    }

    return 0;
}