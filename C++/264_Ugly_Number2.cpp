// Leetcode problem 264-Ugly Number II 
// DP problem
// Cpp solution

/* We have an array k of the first n ugly number. We only know, in the beginning, the first one, which is 1. Then

k[1] = min( k[0]x2, k[0]x3, k[0]x5). The answer is k[0]x2. So we move 2's pointer to 1. Then we test:

k[2] = min( k[1]x2, k[0]x3, k[0]x5). And so on. Be careful about the cases such as 6, in which we need to forward both pointers of 2 and 3, so no else if, onlyif.

x here is multiplication.*/

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n);
        dp[0]=1;
        // three-pointer approach
        int p3=0,p2=0,p5=0;
        for(int i =1;i<n;i++){
        dp[i]=min(dp[p2]*2,min(dp[p3]*3,dp[p5]*5));
        if(dp[i]==dp[p2]*2) p2++;
        if(dp[i]==dp[p3]*3) p3++;
        if(dp[i]==dp[p5]*5) p5++;
        }
        return dp[n-1];
    }
};
