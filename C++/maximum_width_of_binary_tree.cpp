#include<iostream>
#include<vector>
#include<queue>
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
int max_width(Node* root){
    if(root == NULL){
        return 0;
    }
    queue<pair<Node* , int>> q;
    q.push({root, 0});
    int ans = 0;
    while(!q.empty()){
        // Node* newNode = q.front().first;
        
        int qsize = q.size();
        int subtract_val = q.front().second;
        int first, last;
        
        for(int i=0; i<qsize; i++){
            pair<Node*, int> p = q.front();
            int cur_id = p.second - subtract_val;
            q.pop();
            if(i==0){
                first = cur_id;
            }
            if(i==qsize-1){
                last = cur_id;
            }
            if(p.first->left!=NULL){
                int idx = 2*(p.second - subtract_val) +1;
                q.push({p.first->left, idx});
            }
            if(p.first->right!=NULL){
                int idx = 2*(p.second - subtract_val) +2;
                q.push({p.first->right, idx});
            }

        } 
        ans = max(ans, last-first+1);
    }
    return ans;

}
int main()
{   

    int nodes[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    BinaryTree *tree = new BinaryTree();
    Node *root = tree->BuildTree(nodes);
    int Max_width = max_width(root);
    cout<<Max_width;
    return 0;
}