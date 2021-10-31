#include<bits/stdc++.h>
using namespace std;
#define  pb push_back
#define inf 1e18
#define  mp make_pair
#define mod 1000000007
typedef vector<int> vi;
typedef long long int lli;
typedef pair<lli,int> pii;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,x;
    cin>>n>>x;
    vi c(n);
    for(int i=0;i<n;i++)cin>>c[i];
    vector<lli>dp(x+1,inf);
    dp[0]=0;
    for(int i=0;i<n;i++)
        for(int j=0;j+c[i]<=x;j++)
            dp[j+c[i]]=min(dp[j+c[i]],dp[j]+1);
    (dp[x]==inf)?cout<<-1:cout<<dp[x];
    return 0;
}