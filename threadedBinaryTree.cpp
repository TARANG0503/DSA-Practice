#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
	int data;
	bool rt;
	struct Node *left;
	struct Node *right;
	
	Node(int data){
		this->data = data;
		rt = false;
	}
};

Node *root;

void insert(struct Node* root, int data){
	Node *newNode = new Node(data);
	Node *current = root;
	Node *parent = NULL;
	
	while(1){
		parent = current;
		if(data < current->data){
			current = current->left;
			if(current == NULL){
				parent->left = newNode;
				newNode->right = parent;
				newNode->rt = true;
				return;
			}
		}
		else{
			if(current->rt == false){
				current = current->right;
				if(current == NULL){
					parent->right = newNode;
					return;
				}
			}
			else{
				Node *temp = current->right;
				current->right = newNode;
				newNode->right = temp;
				newNode->rt = true;
				return;
			}
		}
	}
}

Node* leftmost(struct Node* node){
	if(node == NULL)
		return NULL;
	else{
		while(node->left != NULL)
			node = node->left;
		return node;
	}
} 

void print(struct Node* root){
	Node *current = leftmost(root);
	while(current != NULL){
		cout << current->data << " ";
		if(current->rt)
			current = current->right;
		else
			current = leftmost(current->right);
	}
	cout << endl;	
}

int main(){
	int rt, data;
	int ch = -1;
	cout << "Enter value of root: ";
	cin >> rt;
	Node *root = new Node(rt);
	while(ch != 3){
		cout << "1. Insert\n2. Display\n3. Exit\n";
		cout << "Enter your choice: ";
		cin >> ch;
		switch(ch){
			case 1: cout << "Enter value: ";
					cin >> data;
					insert(root, data);
					break;
			case 2: print(root);
					break;
			case 3: exit(0);
		}
	}
}


