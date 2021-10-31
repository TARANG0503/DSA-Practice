#include<bits/stdc++.h>
using namespace std;
#define  pb push_back
#define inf 1e18
#define  mp make_pair
#define mod 1000000007
typedef vector<int> vi;
typedef long long int lli;
typedef pair<lli,lli> pii;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<string> s(n+1);
    for(int i=0;i<n;i++) cin>>s[i];
    vector<vector<lli>>dp(n+1,vector<lli>(n+1,0));
    dp[n][n]=1;
    for(int i=n;i>0;i--){
        for(int j=n;j>0;j--){
            if(s[i-1][j-1]!='*'){
                dp[i-1][j]+=dp[i][j];
                dp[i][j-1]+=dp[i][j];
                dp[i-1][j]%=mod;
                dp[i][j-1]%=mod;
            }
        }
    }
     (s[0][0]!='*')?cout<<dp[1][1]:cout<<0;
    return 0;
}