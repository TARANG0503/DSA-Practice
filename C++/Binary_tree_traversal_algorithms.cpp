#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree
{
    int idx = -1;

public:
    Node *BuildTree(int arr[])
    {
        idx++;
        if (arr[idx] == -1)
        {
            return NULL;
        }
        Node *newNode = new Node(arr[idx]);
        newNode->left = BuildTree(arr);
        newNode->right = BuildTree(arr);
        return newNode;
    }
};

void preOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        cout << "NULL ";
    }
    else
    {
        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}
void inOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        cout << "NULL ";
    }
    else
    {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}
void PostOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        cout << "NULL ";
    }
    else
    {
        PostOrderTraversal(root->left);
        PostOrderTraversal(root->right);
        cout << root->data << " ";
    }
}
void LevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *newNode = q.front();
        q.pop();
        if (newNode == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << newNode->data << " ";
            if (newNode->left != NULL)
            {
                q.push(newNode->left);
            }
            if (newNode->right != NULL)
            {
                q.push(newNode->right);
            }
        }
    }
}


int main()
{
    int nodes[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    BinaryTree *tree = new BinaryTree();
    Node *root = tree->BuildTree(nodes);
    preOrderTraversal(root);
    inOrderTraversal(root);
    PostOrderTraversal(root);
    LevelOrderTraversal(root);
    return 0;
}