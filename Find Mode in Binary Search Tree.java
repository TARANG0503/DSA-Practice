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
class Solution {
    public int[] findMode(TreeNode root) {
        
        Map<Integer,Integer> map = new HashMap<Integer,Integer>();
        
        int maxCount = Integer.MIN_VALUE;
        List<Integer> list = new ArrayList<>();
        List<Integer> list1 = new ArrayList<>();
        
        inorder(root,list);
        for(int x: list){
            if(map.containsKey(x))
               map.put(x,map.get(x)+1);
            else{
                map.put(x,1);
            }
        }
        for(Map.Entry m : map.entrySet())
            maxCount=Math.max((int)m.getValue(),maxCount);
    
        for(Map.Entry m : map.entrySet())
            if((int)m.getValue()==maxCount)
               list1.add( (int)m.getKey());
        
        int arr[]=new int[list1.size()];
        
        for(int i=0;i<arr.length;i++)
            arr[i]=(int)list1.get(i);
        
        return arr;
        
    }
    
    public void inorder(TreeNode root,List<Integer> list){
        if(root==null)
            return;
        inorder(root.left,list);
        list.add(root.val);
        inorder(root.right,list);
    }
}
