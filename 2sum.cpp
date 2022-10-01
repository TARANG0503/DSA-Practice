class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
       // v.reserve(nums.size());
       //  cout<<"Size of v: "<<nums.size()<<endl;
        /*for(int i=0;i<v.size();i++)
        {
            v.push_back(nums[i]);
        }*/
      unordered_map<int,int> m;
        
        for(int i=0;i<nums.size();i++)
        {
          int x = nums[i];
          int y = target-x;
        if(m.find(y)!=m.end())
            return {i,m[y]};
        
        m[nums[i]] = i;
            
        }
               
       
       
       
        return {-1,-1};
    }
  
};
