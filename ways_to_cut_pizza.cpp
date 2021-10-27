/*
Leetcode HARD
Number of ways to cut a pizza
Author: Rajat Jain
Intuition: At each point, we either make a horizontal or a vertical cut, so in order to check whether the cut is valid or not we need to know 
if that submatrix has >0 apples. If we keep checking it on each recursive call, the complexity will blow up. We memoize this by storing the number 
of apples in the submatrix (i,j) to (n,m) in has[i][j] (it can be thought of as a prefix sum). 
Now in the updateDP function we pass the number of cuts still left and the iterate over rows and columns and made recrusive calls for valid cuts.
Our answer is dp[0][0][k-1]
*/

int mod = 1e9+7;
int updateDP(int i, int j, vector<vector<int>> &has,int k, vector<vector<vector<int>> > &dp){
    int n = has.size(), m = has[0].size();
    if(i>=n && j>=m) return 0;
    if(k<=0) return has[i][j];
    
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    
    int cnt = 0;
    //p is the row where the cut is made
    for(int p=i+1;p<n;p++)
        if((has[i][j]-has[p][j])>0){
            cnt= (cnt+updateDP(p,j,has,k-1,dp))%mod;
        }
    //p is the column where the cut is made
    for(int p=j+1;p<m;p++)
        if((has[i][j]-has[i][p])>0){
            cnt= (cnt+updateDP(i,p,has,k-1,dp))%mod;
        }
    dp[i][j][k] = cnt;
    return dp[i][j][k];
}
int ways(vector<string>& pizza, int k) {
    int n = pizza.size(), m = pizza[0].size();
    vector<vector<int>> has(n, vector<int>(m,0));

    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            has[i][j] = (pizza[i][j]=='A');
            if(i+1<n && j+1<m){
                has[i][j] = has[i][j] + has[i+1][j]+has[i][j+1]-has[i+1][j+1];
            }
            else if(i+1<n){
                has[i][j] = has[i][j] + has[i+1][j];
            }
            else if(j+1<m){
                has[i][j] = has[i][j] + has[i][j+1];
            }
        }
    }
    vector<vector<vector<int>> >dp(n, vector<vector<int>>(m,vector<int>(k,-1)));
    return updateDP(0,0,has,k-1,dp);
}