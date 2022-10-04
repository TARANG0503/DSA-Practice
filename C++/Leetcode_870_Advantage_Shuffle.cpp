class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        multiset<int> ms(nums1.begin(),nums1.end());
        for(int x : nums2) {
            auto it = ms.upper_bound(x);
            if(it==ms.end()) {
                ans.push_back(*ms.begin());
                ms.erase(ms.begin());
            }
            else {
                ans.push_back(*it);
                ms.erase(it);
            }
        }
        return ans;
    }
};
