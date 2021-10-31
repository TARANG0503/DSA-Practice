#include<bits/stdc++.h>
using namespace std;
#define  pb push_back
#define inf 1e18
#define mod 1000000007
#define  mp make_pair
typedef vector<int> vi;
typedef long long int lli;
typedef pair<int,int> pii;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
lli power(lli x, lli y, long long int m = mod) { lli ans = 1; x %= m; while (y) {if (y & 1)ans = (x * ans) % m; x = (x * x) % m; y >>= 1;} return ans;}
int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<lli>dp(n+1,inf);
    dp[n]=0;
    for(int i=n;i>=0;i--){
        int l=i;
        while(l){
            int d=l%10;
            dp[i-d]=min(dp[i-d],dp[i]+1);
            l/=10;
        }
    }
    cout<<dp[0];
    return 0;
}