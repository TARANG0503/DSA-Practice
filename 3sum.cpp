class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        ListNode* pre =nullptr;
        int remainder = 0;
        int sum =0;
        while( l1 != nullptr && l2 != nullptr){
            l1->val = l1->val + l2->val + remainder;
            remainder = l1->val/10;
            l1->val = l1->val%10;
            
            pre = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        if(l1 == nullptr){
            pre->next = l2;
            l1 = l2;
        }
        
        while( l1 != nullptr){
            l1->val = l1->val + remainder;
            remainder = l1->val/10;
            l1->val = l1->val%10;
                
            pre = l1;
            l1 = l1->next;
        }
            
        if(remainder != 0){
            pre->next = new ListNode(remainder);
        }
        
        
        
        

        
        
        
  SECOND METHOD;
        
        
        class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i =0;
        int sum = 0;
        int j=0;
        int n = nums.size();
        vector<int> ans;
        vector<vector<int>> two;
        while(j<n)
        {
            sum = sum+nums[j];
            ans.push_back(nums[j]);
            if((j-i+1)<3)
            {
                j++;
            }
            else if((j-i+1)==3)
            {
                if(sum==0)
                {
                    two.push_back(ans);
                }
                ans.erase(ans.begin());
                sum = sum-nums[i];
                i++;
                j++;
            }
        }
        return two;
    }
};
        return head;
    }
};
