using System;
 
// A binary tree node
public class Node {
    public int data;
    public Node left, right;
 
    public Node(int item)
    {
        data = item;
        left = right = null;
    }
 
    public virtual Node Left
    {
        set { this.left = value; }
    }
 
    public virtual Node Right
    {
        set { this.right = value; }
    }
}
 
class inorderlevel {
    public Node root;
 
    public virtual Node buildTree(int[] arr, int[] level)
    {
        Node startnode = null;
        return constructTree(startnode, level, arr, 0,
                             arr.Length - 1);
    }
 
    public virtual Node
    constructTree(Node startNode, int[] levelOrder,
                  int[] inOrder, int inStart, int inEnd)
    {
 
        // if start index is more than end index
        if (inStart > inEnd) {
            return null;
        }
 
        if (inStart == inEnd) {
            return new Node(inOrder[inStart]);
        }
 
        bool found = false;
        int index = 0;
 
        // it represents the index in inOrder
        // array of element that appear first
        // in levelOrder array.
        for (int i = 0; i < levelOrder.Length - 1; i++) {
            int data = levelOrder[i];
            for (int j = inStart; j < inEnd; j++) {
                if (data == inOrder[j]) {
                    startNode = new Node(data);
                    index = j;
                    found = true;
                    break;
                }
            }
            if (found == true) {
                break;
            }
        }
 
        // elements present before index are
        // part of left child of startNode.
        // elements present after index are
        // part of right child of startNode.
        startNode.Left
            = constructTree(startNode, levelOrder, inOrder,
                            inStart, index - 1);
        startNode.Right
            = constructTree(startNode, levelOrder, inOrder,
                            index + 1, inEnd);
 
        return startNode;
    }
 
    /* Utility function to print inorder
       traversal of binary tree */
    public virtual void printInorder(Node node)
    {
        if (node == null) {
            return;
        }
        printInorder(node.left);
        Console.Write(node.data + " ");
        printInorder(node.right);
    }
 
    // Driver Code
    public static void Main(string[] args)
    {
        GFG tree = new GFG();
        int[] arr = new int[] { 4, 8, 10, 12, 14, 20, 22 };
        int[] level
            = new int[] { 20, 8, 22, 4, 12, 10, 14 };
        int n = arr.Length;
        Node node = tree.buildTree(arr, level);
 
        /* Let us test the built tree by
        printing Inorder traversal */
        Console.Write("Inorder traversal of the "
                      + "constructed tree is "
                      + "\n");
        tree.printInorder(node);
    }
}