//BST- To insert into a BST and also check whether a tree is a valid binary search tree or not.

#include <iostream>
#include <climits>
using namespace std;
 struct Node
{
    int data;
    Node* left = nullptr; 
    Node* right = nullptr;
    Node() {}
    Node(int data): data(data) {}
};
 
//To insert node into the BST
Node* insert(Node* root, int val)
{
    // if root is NULL
    if (root == nullptr) {
        return new Node(val);
    }
    // if val is less than the root recur for left subtree
    if (val < root->data) {
        root->left = insert(root->left, val);
    }
    // if val is more than the root recur for right subtree
    else {
        root->right = insert(root->right, val);
    }
    return root;
}
 
// Check if valid BST or not, using valid range [-INFINITY, INFINITY]
bool checkBST(Node* node, int minval, int maxval)
{
    // base case
    if (node == nullptr) {
        return true;
    }

    // if node is not in the valid range
    if (node->data < minval || node->data > maxval) {
        return false;
    }
 
    // recursively check left and right subtrees with an updated range
    return checkBST(node->left, minval, node->data) && checkBST(node->right, node->data, maxval);
}
 
// Function to determine whether a given binary tree is a BST
void checkBST(Node* root)
{
    if (checkBST(root, INT_MIN, INT_MAX)) {
        cout<<"This tree is a BST."<<endl;
    }
    else {
        cout<<"This tree is not a BST."<<endl;
    }
}
int main()
{
    int arr[] = { 15, 10, 20, 8, 12, 16, 25 };
    Node* root = nullptr;
    for (int val: arr) {
        root = insert(root, val);
    }
    checkBST(root);
    return 0;
}