/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        
        queue<TreeNode*> q;
        vector<double> v1;
       q.push(root);
        
        while(!q.empty())
        {   
            double ans=0;
            int n = q.size();
            
           // double avg;
            
            for(int i=0;i<n;i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
                
                ans+=temp->val;
                
            }
            
            double avg = (double)ans/n;
            
            v1.push_back(avg);
        }
        
        return v1;
    }
};