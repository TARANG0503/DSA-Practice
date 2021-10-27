/*
Leetcode HARD
Largest submatrix with 1s after rearrangement (question link: https://leetcode.com/problems/largest-submatrix-with-rearrangements/)
Author: Rajat Jain
Intuition: For each column first store the number of consecutive 1s ending at each position. Now imagine your submatrix ends in row j, 
you have the count of 1s above each position in row j and so you'd be able to choose the columns that'll give the optimum answer for j.
Now repeat this for all j's. PS: By sorting each row and starting iterating from the end, we know that when we reach index j, the number 
of 1s ending at j would be the limiting reagent and so we use (m-j)*cnt[i][j].

*/

int largestSubmatrix(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int> > cnt(n, vector<int>(m,0));
    for(int j=0;j<m;j++){
        if(matrix[0][j]) cnt[0][j] = 1;        
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]) cnt[i][j]=cnt[i-1][j]+1;
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        sort(cnt[i].begin(),cnt[i].end());
        for(int j=m-1;j>=0;j--){
            ans = max(ans,(m-j)*cnt[i][j]);
        }
    }
    return ans;
}