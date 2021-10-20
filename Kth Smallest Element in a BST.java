/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution 
{
    public void inorder(TreeNode root,List<Integer>set)
    {
       if(root==null)
       {
           return;
       }
        inorder(root.left,set);
        set.add(root.val);
        inorder(root.right,set);
    }
    public int kthSmallest(TreeNode root, int k) 
    {
         List<Integer>set=new ArrayList<>();
        inorder(root,set);
        return(set.get(k-1));
    }
}
