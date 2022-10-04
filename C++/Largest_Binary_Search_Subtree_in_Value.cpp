// Problem link: https://binarysearch.com/problems/Largest-Binary-Search-Subtree-in-Value

//Code:

/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
bool check(Tree* root, int min_val, int max_val) {
    if(!root) return true;
    if(root -> val >= max_val) return false;
    if(root -> val <= min_val) return false;
    return check(root -> left, min_val, root -> val) and check(root -> right, root -> val, max_val);
}

int sum(Tree* root) {
    if(!root) return 0;
    return (root -> val + sum(root -> left) + sum(root -> right));
}

int solve(Tree* root) {
    if(check(root, INT_MIN, INT_MAX)) {
        return sum(root);
    }
    int left = solve(root -> left);
    int right = solve(root -> right);

    return max(left, right);
}

// Solution Explanation

// Intuition

// The problem is basically a combination of two easy problems:

//     Check if a given tree is a binary search tree or not.
//     Find the sum of a binary search tree.

// Implementation

// We will use two different functions for the two tasks.

// The bool check functions checks is each subtree is a BST or not. If the root is the BST, then we will have that as our answer, else we will check for each child node and find the sum.

// Then, a simple greedy algorithm to check for the maximum sum that we get and that will be our answer.
// Time Complexity

// O(n^2) Checking each node if the subtree at that node is a valid BST or not.
// Space Complexity

// O(n) Depends on the height of the tree.
