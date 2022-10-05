#include<bits/stdc++.h>
using namespace std;
void online()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
void solve(string str,string sol,vector<string> &soltuion)
{
    if(str.length()==0)
    {
        //cout<<sol<<endl;
        soltuion.push_back(sol);
        return;
    }
    string temp1=sol;
    string temp2=sol;
    temp2+=str[0];
    str.erase(str.begin()+0);
    solve(str,temp1,soltuion);
    solve(str,temp2,soltuion);
}
int main(){
    online();
    string str;
    cin>>str;
    vector<string> sol;
    solve(str,"",sol);
    for(auto a: sol)
    cout<<a<<endl;
    return 0;
}