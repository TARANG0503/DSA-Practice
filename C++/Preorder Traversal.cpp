#include <iostream>

using namespace std;

struct node 
{
        int element;
        struct node * left;
        struct node * right;
};

/*To create a new node*/
struct node * createNode(int val) 
{
        struct node * Node = (struct node * ) malloc(sizeof(struct node));
        Node -> element = val;
        Node -> left = NULL;
        Node -> right = NULL;

        return (Node);
}

/*function to traverse the nodes of binary tree in preorder*/
void traversePreorder(struct node * root) 
{
        if (root == NULL)
                return;
        cout << " " << root -> element << " ";
        traversePreorder(root -> left);
        traversePreorder(root -> right);
}

int main()
{
        struct node * root = createNode(39);
        root -> left = createNode(29);
        root -> right = createNode(49);
        root -> left -> left = createNode(24);
        root -> left -> right = createNode(34);
        root -> left -> left -> left = createNode(14);
        root -> left -> left -> right = createNode(27);
        root -> right -> left = createNode(44);
        root -> right -> right = createNode(59);
        root -> right -> right -> left = createNode(54);
        root -> right -> right -> right = createNode(69);

        cout << "\n The Preorder traversal of given binary tree is -\n";
        traversePreorder(root);
        return 0;
}
