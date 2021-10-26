// C++ program to create an AVL Tree
#include<iostream> 
#include<stdlib.h>
using namespace std; 

struct Node 
{ 
	public: 
	int key; 
	Node *left; 
	Node *right; 
	int height; 
};

int height(Node *N){ 
	if (N == NULL) 
		return 0; 
	return N->height; 
} 

int max(int a, int b){ 
	return (a > b) ? a : b; 
} 

/* Helper function that allocates a 
new node with the given key and 
NULL left and right pointers. */
Node* newNode(int key){ 
	Node* node = new Node(); 
	node->key = key; 
	node->left = NULL; 
	node->right = NULL; 
	node->height = 1; // new node is initially added at leaf
	return(node); 
} 

Node *rightRotate(Node *y) 
{ 
	Node *x = y->left; 
	Node *T2 = x->right; 

	// Perform rotation 
	x->right = y; 
	y->left = T2; 

	// Update heights 
	y->height = max(height(y->left), height(y->right)) + 1; 
	x->height = max(height(x->left), height(x->right)) + 1; 

	// Return new root 
	return x; 
} 

Node *leftRotate(Node *x){ 
	Node *y = x->right; 
	Node *T2 = y->left; 

	// Perform rotation 
	y->left = x; 
	x->right = T2; 

	// Update heights 
	x->height = max(height(x->left), height(x->right)) + 1; 
	y->height = max(height(y->left), height(y->right)) + 1; 

	// Return new root 
	return y; 
} 

// Get Balance factor of node N 
int getBalance(Node *N){ 
	if (N == NULL) 
		return 0; 
	return height(N->left) - height(N->right); 
} 

/* Recursive function to insert a key 
in the subtree rooted with node and 
returns the new root of the subtree.*/ 
Node* insert(Node* node, int key) 
{ 
	// 1. Perform the normal BST insertion
	if (node == NULL) 
		return(newNode(key)); 

	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 
	else 
		return node; 

	// 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left), height(node->right)); 

	/* 3. Get the balance factor of this ancestor 
		node to check whether this node became 
		unbalanced */
	int balance = getBalance(node); 

	// If this node becomes unbalanced, then there are 4 cases

	// Left Left Case 
	if (balance > 1 && key < node->left->key) 
		return rightRotate(node); 

	// Right Right Case 
	if (balance < -1 && key > node->right->key) 
		return leftRotate(node); 

	// Left Right Case 
	if (balance > 1 && key > node->left->key){ 
		node->left = leftRotate(node->left); 
		return rightRotate(node); 
	} 

	// Right Left Case 
	if (balance < -1 && key < node->right->key){ 
		node->right = rightRotate(node->right); 
		return leftRotate(node); 
	} 

	/* return the (unchanged) node pointer */
	return node; 
} 

void preOrder(Node *root){ 
	if(root != NULL){ 
		cout << root->key << " "; 
		preOrder(root->left); 
		preOrder(root->right); 
	} 
} 
void inOrder(Node *root){ 
	if(root != NULL){ 	
		inOrder(root->left); 
		cout << root->key << " "; 
		inOrder(root->right); 
	} 
} 

int main() 
{ 
	Node *root = NULL;
	int choice = -1, value;
	
	while(choice != 4){
		cout << "\n--------AVL Tree--------" << endl;
		cout << "1. Insert" << endl;
		cout << "2. Preorder traversal" << endl;
		cout << "3. Inorder traversal" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch(choice){
			case 1: cout << "Enter value to be inserted: ";
					cin >> value;
					root = insert(root, value);
					break;
			case 2: cout << "Preorder traversal of the constructed AVL tree is: "; 
					preOrder(root);
					cout << endl;
					break;
			case 3: cout << "Inorder traversal of the constructed AVL tree is: "; 
					inOrder(root);
					cout << endl;
					break;
			case 4: exit(0);
		}
	} 
} 
