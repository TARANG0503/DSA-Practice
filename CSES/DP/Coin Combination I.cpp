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
    vector<lli>dp(x+1,0);
    dp[0]=1;
    for(int i=0;i<=x;i++)
        for(int j=0;j<n;j++)
            if(i+c[j]<=x){dp[i+c[j]]+=dp[i];dp[i+c[j]]%=mod;}
    cout<<dp[x]%mod;
    return 0;
}