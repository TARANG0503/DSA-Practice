#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        if(nums.size() < 4)
            return {};
        sort(nums.begin(),nums.end());
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int two_sum = nums[i] + nums[j];
                int rem = target - two_sum;
                int low = j+1;
                int high = n-1;
                while(low < high){
                    if(nums[low] + nums[high] > rem)
                        high--;
                    else if(nums[low] + nums[high] < rem)
                        low++;
                    else{
                        vector <int> temp(4);
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[low];
                        temp[3] = nums[high];
                        ans.push_back(temp);
                        while(low < high && nums[low] == temp[2])
                            low++;
                        while(low < high && nums[high] == temp[3])
                            high--;
                    }
                }
                while(j + 1 < n && nums[j] == nums[j+1])
                    j++;
            }
            while(i + 1 < n && nums[i] == nums[i+1])
                i++;
        }
        return ans;
    }
};