class Solution {
public:
    void solve(vector<int> arr, vector<int> output, int index, vector<vector<int>>&ans)
    {
        if(index >= arr.size())
        {
            ans.push_back(output);
            return;
        }
        
        solve(arr, output, index + 1, ans);
        
        output.push_back(arr[index]);
        
        solve(arr, output, index + 1, ans);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> output;
        
        int index = 0;
        
        solve(nums, output, 0, ans);
        
        return ans;
    }
};