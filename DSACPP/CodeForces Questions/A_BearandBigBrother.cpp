/*Author : Manraj Singh */
#include <bits/stdc++.h>
using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a , b;


    cin>>a>>b;
    int count = 0;

    while (a <= b)
    {
        a *= 3;
        b *= 2;
        count++;
    }

    cout<<count<<endl;
    



    return 0;
}