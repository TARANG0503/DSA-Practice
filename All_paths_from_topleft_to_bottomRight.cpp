//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  private:
    int mod=1000000007;
  public:
    long long int numberOfPaths(int m, int n){
        // code here
        vector<vector<long long int>>dp(m,vector<long long int>(n,0));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 || j==n-1){
                    dp[i][j]=1;
                }else{
                    dp[i][j]=(dp[i+1][j] + dp[i][j+1])%mod;
                }
            }
        }
        return dp[0][0]%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}

// } Driver Code Ends