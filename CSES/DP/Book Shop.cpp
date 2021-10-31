#include<bits/stdc++.h>
using namespace std;
#define  pb push_back
#define inf 1e18
#define  mp make_pair
typedef vector<int> vi;
typedef long long int lli;
typedef pair<int,int> pii;
int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,x;
    cin>>n>>x;
    vi cost(n),pg(n),dp(x+1,0);
    for(int &u:cost)cin>>u;
    for(int &u:pg)cin>>u;
    for(int j=0;j<n;j++)
    for(int i=0;i+cost[j]<=x;i++)
        dp[i]=max(dp[i],dp[i+cost[j]]+pg[j]);
    cout<<dp[0];
    return 0;
}