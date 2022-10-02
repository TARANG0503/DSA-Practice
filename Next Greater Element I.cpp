//https://leetcode.com/problems/next-greater-element-i/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      //O(N+M)
        vector<int> ans;
        stack<int> st;
        unordered_map<int,int> m;
        for(int n:nums2)
        {  while(!st.empty() and st.top()<n)
        {
            m[st.top()]=n;
            st.pop();
        }
            st.push(n);
        }
        
        for(auto it:nums1)
        {
            if(m.count(it))
                ans.push_back(m[it]);
            else
                ans.push_back(-1);
        }
        return ans;
        //O(M*N)
      /*  for(int i=0;i<nums1.size();i++)
        { int j;
            for(j=0;j<nums2.size();j++)
            { if(nums2[j]==nums1[i]) break;
                
            }
         int ele=-1;
         for(int k=j;k<nums2.size();k++)
         {
             if(nums2[k]>nums1[i])
             {
                 ele=nums2[k];
                 break;
             }
         }
         ans.push_back(ele);
        }
        return ans;*/
    }
};