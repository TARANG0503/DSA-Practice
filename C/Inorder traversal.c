 #include <stdio.h>

 #include <stdlib.h>

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
 /*function to traverse the nodes of binary tree in Inorder*/
 void traverseInorder(struct node * root) 
 {
         if (root == NULL)
                 return;
         traverseInorder(root -> left);
         printf(" %d ", root -> element);
         traverseInorder(root -> right);
 }
 
 int main() 
 {
         struct node * root = createNode(40);
         root -> left = createNode(30);
         root -> right = createNode(50);
         root -> left -> left = createNode(25);
         root -> left -> right = createNode(35);
         root -> left -> left -> left = createNode(15);
         root -> left -> left -> right = createNode(28);
         root -> right -> left = createNode(45);
         root -> right -> right = createNode(60);
         root -> right -> right -> left = createNode(55);
         root -> right -> right -> right = createNode(70);
         printf("\n The Inorder traversal of given binary tree is -\n");
         traverseInorder(root);
         return 0;
 }
