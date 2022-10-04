#include<iostream>
#include<vector>
using namespace std;
 class Node {
    public : 
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this -> data = data;
            this -> left = NULL;
            this -> right = NULL;
        }

        ~Node() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };
void inorderTraverse(Node* root, vector<int> &in){
    if(root == NULL){
        return;
    }
    inorderTraverse(root -> left, in);
    in.push_back(root ->data);
    inorderTraverse(root -> right, in);
    
}

Node* flatten(Node* root)
{
    vector<int> inorderVal;
    inorderTraverse(root,inorderVal);
    int n = inorderVal.size();
    //new root bnao
    Node* newRoot = new Node(inorderVal[0]);
    Node* curr = newRoot;
    
    
    for(int i=1; i<n; i++){
        Node* temp = new Node(inorderVal[i]);
        
        curr -> left = NULL;
        curr -> right = temp;
        curr = temp;
    }
    
    //3rd step
    curr -> left = NULL;
    curr -> right = NULL;
    
    return newRoot;
}
