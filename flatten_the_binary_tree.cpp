/* Algorithm to Flatten the Binary tree into linked list:

    Step 1 :- Create a Stack, push the root into the stack;
    Step 2 :- Perform Pop onto the stack, push the child/children of the node, Recently popped from the stack (let's say node-N1), into the stack.
              (Keep track of previous popped node.)
    Step 3 :- If previously Popped node exits make its right child point to node that is popped in step 2(i.e N1), and left child as NULL,
              update the previous pop to N1;
          ----Repeat Step 2 and 3 until stack gets empty-----
*/

#include<iostream>
#include<stack>
#include<queue>

using namespace std;

class Node
{
    int data = 0;
    Node *left=NULL, *right=NULL;

public:
    Node* Create_Node(int);
    Node* Create_Binary_Tree(Node*, int);
    Node* Flatten_the_Tree(Node*);
    void Print(Node*);
};

int main()
{
    int n=6, i=0;
    int arr[] = {42, 23, 74, 11, 65, 58};
    Node obj, *head=NULL;
    for(; i<n; i++)
        head = obj.Create_Binary_Tree(head, arr[i]);

    cout<<"Binary tree, ";
    obj.Print(head);

    head = obj.Flatten_the_Tree(head);
    cout<<"Flatten Binary tree, ";
    obj.Print(head);
}

Node* Node::Flatten_the_Tree(Node *root)
{
    //Create the stack
    stack <Node*> s;

    //Push the root into the stack
    s.push(root);

    //Pointer to keep track of previous pop
    Node* prev = NULL;
    while(!s.empty())
    {
        //Pointer to keep track of recent pop
        Node *temp = s.top();
        //Pop the top of the stack
        s.pop();

        //Push the children of recently popped node into the stack
        if(temp->right)
        s.push(temp->right);
        if(temp->left)
        s.push(temp->left);

        //If previous pop exists update its child
        if(prev)
        {
            prev->right = temp;
            prev->left = NULL;
        }

        //Update Previous pop
        prev = temp;
    }
    return root;
}

Node* Node:: Create_Node(int data)
{
    Node *temp =  new Node();
    temp->data = data;
    return temp;
}

Node* Node:: Create_Binary_Tree(Node *root, int data)
{
    if(!root)
        return Create_Node(data);
    else if(root->data > data)
        root->left = Create_Binary_Tree(root->left, data);
    else if(root->data < data)
        root->right = Create_Binary_Tree(root->right, data);
    return root;

}

void Node::Print(Node *root)
{
    queue <Node*> q;
    q.push(root);
    cout<<"BFS traversal: ";
    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if(temp->left)
        q.push(temp->left);
        if(temp->right)
        q.push(temp->right);

        cout<<temp->data<<" ";
    }
    cout<<endl;
}

/*
    Output:
        Binary tree, BFS traversal: 42 23 74 11 65 58
        Flatten Binary tree, BFS traversal: 42 23 11 74 65 58
*/
