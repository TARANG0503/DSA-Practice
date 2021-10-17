#include<bits/stdc++.h>
using namespace std;

struct Tree_node{
    int data;
    struct Tree_node *left, *right;

    Tree_node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

void preorder(struct Tree_node *root)
{
    if(root==NULL)
      return;
    
    cout<<(root->data)<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct Tree_node *root)
{
    if(root==NULL)
     return;

    inorder(root->left);
    cout<<(root->data)<<" ";
    inorder(root->right); 
}
void postorder(struct Tree_node *root)
{
    if(root==NULL)
     return;

    postorder(root->left);
    postorder(root->right);
    cout<<(root->data)<<" "; 
}
int main()
{
    struct Tree_node* root = new Tree_node(10);
    root->left = new Tree_node(20);
    root->right = new Tree_node(30);
    root->left->left = new Tree_node(40);
    root->left->right = new Tree_node(50);
    root->right->right = new Tree_node(60);

    cout<<"Preorder Traversal: ";
    preorder(root);

    cout<<"\nInorder Traversal: ";
    inorder(root);

    cout<<"\nPostorder Traversal: ";
    postorder(root);

    return 0;
}