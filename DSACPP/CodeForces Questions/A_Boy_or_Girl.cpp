/*Author : Manraj Singh */
#include <bits/stdc++.h>
using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string c;
    cin>>c;
    set<char> s;

    for (int i = 0; i < c.size(); i++)
    {
        s.insert(c[i]);
    }

    if(s.size()%2 == 1){

        cout<<"IGNORE HIM!\n";
    }
    else{

        cout<<"CHAT WITH HER!\n";
    }
    

    return 0;
}