class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256,-1);
        int ans=0 , n=s.length();
        int l=0 ;
        for(int r=0 ; r<n ; r++) {
            l=max(l,last[s[r]]+1);
            ans=max(ans,r-l+1);
            last[s[r]]=r ;
        }
        return ans ;
    }
};
