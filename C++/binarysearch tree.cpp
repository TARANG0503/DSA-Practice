#include<iostream>
using namespace std;
class tree{
	public:
		int data;
		tree *left;
		tree *right;
		void insert(int data);
		void dele(tree *t, int key);
		tree * min(tree *t);
};
tree *root=NULL;
tree * tree::min(tree *t)
{
	tree *current=t;
	while(current!=NULL&&current->left!=NULL)
	{
		current=current->left;
	}
	return current;
}
void tree::insert(int data)
{
	tree *temp=new tree();
	temp->data=data;
	temp->left=temp->right=NULL;
	if(root==NULL)
	{
		root=temp;
		return;
	}
	tree *t=new tree();
	t=root;
	bool h;
	while(true)
	{
		if(temp->data<=t->data)
		{
			h=true;
			if(t->left==NULL)
			{
				break;
			}
			t=t->left;
		}
		else if(temp->data>t->data)
		{
			h=false;
			if(t->right==NULL)
			{
				break;
			}
			t=t->right;
		}
	}
	if(h)
	{
		t->left=temp;
	}
	if(!h)
	{
		t->right=temp;
	}
}
void tree::dele(tree *t, int key)
{
	if(t==NULL)
	{
		cout<<"empty";
		return;
	}
	else if(key<t->data)
	{
		dele(t->left, key);
	}
	else if(key>t->data)
	{
		dele(t->right, key);
	}
	else
	{
		if(t->left==NULL && t->right==NULL) // zero child
		{
			delete t;
			t=NULL;
			return;
		}
		if(t->left==NULL)  //one child
		{
			tree *temp=t;
			t=t->right;
			delete temp;
			return;
		}
		if(t->right==NULL)
		{
			tree *temp=t;
			t=t->left;
			delete temp;
			return;
		}
			tree *temp=min(t->right);  //to find minimum node on the right side
			t->data=temp->data;
            dele(t->right, temp->data);
	}
}
int main()
{
	tree t;
	t.insert(4);
	t.insert(5);
	t.insert(3);
	t.dele(root, 4);
	cout<<root->right->data;
}
