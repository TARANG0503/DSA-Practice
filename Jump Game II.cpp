class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int currReach=0, maxReach=0;
        int nofSteps=0;
        for(int i=0; i<n; i++){
            if(currReach<i){
                nofSteps++;
                currReach=maxReach;
            }
            
            maxReach=max(maxReach, nums[i]+i);
        }
        
        return nofSteps;
    }
};
