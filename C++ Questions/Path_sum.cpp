// Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.
// A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

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
    vector<vector<int>>v;
    void path(TreeNode* root, int t, int sum, vector<int>&a){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            if(sum+root->val==t){
                a.push_back(root->val);
                v.push_back(a);
                a.pop_back();
                return;
            }
            return;
        }
        if(root->left){
            a.push_back(root->val);
            path(root->left,t,sum+root->val,a);
            a.pop_back();
        }
        if(root->right){
            a.push_back(root->val);
            path(root->right,t,sum+root->val,a);
            a.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>a;
        path(root,targetSum,0,a);
        return v;
    }
};
