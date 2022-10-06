// Bits solution
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int mask = 1 << nums.size();
        vector<vector<int>> ans(mask);

        while (mask)
        {
            for (int i = 0; i < nums.size(); ++i)
            {
                if ((1 << i) & mask)
                    ans[mask - 1].push_back(nums[i]);
            }

            mask -= 1;
        }

        return ans;
    }
};

// Backtracking
class Solution
{
    void solve(vector<vector<int>> &ans, vector<int> subset, vector<int> &nums, int start)
    {
        ans.push_back(subset);
        for (int i = start; i < nums.size(); ++i)
        {
            subset.push_back(nums[i]);
            solve(ans, subset, nums, i + 1);
            subset.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> subset;

        solve(ans, subset, nums, 0);
        return ans;
    }
};