// For minimum deletion substract length of palindrome subsequence from total length
// For minimum insertion substract length of palindrome subsequence from total length

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string A) {
        //code here
        
        string B = A;
        reverse(B.begin(),B.end());
        
        int n = A.length();
        
        vector<vector<int>> t(n+1,vector<int>(n+1,0));
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(A[i-1]==B[j-1])
                t[i][j] = 1+t[i-1][j-1];
                
                else
                {
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        //cout<<t[n][n];
        return t[n][n];
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
