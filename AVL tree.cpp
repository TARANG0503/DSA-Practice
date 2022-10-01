#include<iostream>
#include<queue>
using namespace std;
class tree{
	public:
		tree *left;
		tree *right;
		int data;
		void insert(int data);
		int check(tree *node);
		void rightrotate(tree *node);
		void leftrotate(tree *node);
		void preorder(tree *node);
		void deletion(tree *node);
		queue<tree *> q1;
		void dele(tree *node, int g);
		tree * min(tree *node);
};
tree * tree::min(tree *node)
{
	while(node->left!=NULL&&node->right!=NULL)
	{
		node=node->left;
	}
	if(node->left!=NULL)
	{
		return node->left;
	}
	else
	{
		return node->right;
	}
}
void tree::dele(tree *node, int g)
{
   if(g==1)
   {
   	 if(node->left->left==NULL && node->left->right==NULL)
   	 {
   	 	node->left=NULL;
   	 	return;
     }
     if(node->left->left!=NULL && node->left->right==NULL)
     {
     	node->left=node->left->left;
     	return;
	 }
	 if(node->left->right!=NULL&& node->left->left==NULL)
	 {
	 	node->left=node->left->right;
	 	return;
	 }
	 else
	 {
	   tree *u=new tree();
	   u=min(node->left);
	   node->left->data=u->data;
	   deletion(u);
	   return;
	 }
   }
   if(g==0)
   {
   	if(node->right->left==NULL && node->right->right==NULL)
   	 {
   	   node->right=NULL;
	   return;	
     }
     if(node->right->left!=NULL && node->right->right==NULL)
     {
     	node->right=node->right->left;
     	return;
	 }
     if(node->right->right!=NULL&& node->right->left==NULL)
	 {
	 	node->right=node->right->right;
	 	return;
	 }
	 else
	 {
	 	tree *u=
		 u=min(node->right);
		 node->right->data=u->data;
		 deletion(u);
		 return;
	 }
   }
}
tree *head=NULL;
void tree::preorder(tree *node)
{
	if(node==NULL)
	{
		return ;
	}
	cout<<node->data;
	preorder(node->left);
	preorder(node->right);
}
int h=-1;
bool tr;
void tree::insert(int data)
{
	tree *temp=new tree();
	temp->data=data;
	temp->right=temp->left=NULL;
	if(head==NULL)
	{
	   head=temp;
	   return;
	}
	tree *t=new tree();
	t=head;
	while(true)
	{
		if(temp->data<=t->data)
		{
			if(t->left==NULL)
			{
				t->left=temp;
				break;
			}
			t=t->left;
		}
		else if(temp->data>t->data)
		{
			if(t->right==NULL)
			{
				t->right=temp;
				break;
			}
			t=t->right;
		}
	}
	check(head);
	cout<<h<<endl;
	if(h!=1&&h!=0)
	{
		return;
	}
	if(tr&&(head->left->right==NULL||head->left->right->left==NULL)&&h==1)
	{
		rightrotate(head);
		return;
	}
	if(tr&&(head->left->left->left==NULL||head->left->right==NULL)&&h==1)
	{
		leftrotate(head->left);
		rightrotate(head);
		return;
	}
	if(!tr&&(head->right->left->left==NULL||head->right->left==NULL)&&h==0)
	{
		leftrotate(head);
		return;
	}
	if(!tr &&(head->right->right->left==NULL||head->right->right==NULL)&&h==0)
	{
		rightrotate(head->right);
		leftrotate(head);
		return;
	}
}
int tree::check(tree *node)
{
	if(node==NULL)
	{
		return 0;
	}
	else
	{
	int l=check(node->left);
	int r=check(node->right);
	if(l>=r)
	{
		tr=true;
		if((l-r)>1)
		{
			h=1;
		}
		return l+1;
	}
	else
	{
		tr=false;
		if((r-l)>1)
		{
			h=0;
		}
		return r+1;
	}
    }
}
void tree::rightrotate(tree *node)
{
	tree *t=new tree();
	t=node->left;
	node->left=t->right;
	t->right=node;
	if(node==head)
	{
		head=t;
	}
	else 
	{
		if(tr)
		{
			head->left=t;
		}
		else
		{
			head->right=t;
		}
	}
	return;
}
void tree::leftrotate(tree *node)
{
     tree *t=new tree();
     t=node->right;
     node->right=t->left;
     t->left=node;
     if(node!=head)
     {
     	if(tr)
     	{
     		head->left=t;
	    }
	    else
	    {
	    	head->right=t;
		}
	 }
	 else 
	 {
	 	head=t;
	 }
     return;
}
void tree::deletion(tree *node)
{
   tree *t=new tree();
   queue<tree *> my;
   while(true)
   {
   	t=q1.front();
   	if(t->left==node)
   	{
   		dele(t,1);
   		break;
	}
	if(t->right==node)
	{
		dele(t,0);
		break;
	}
	while(q1.empty())
	{
		my.push(q1.front());
		q1.pop();
	}
   }
   return;
}
int main()
{
	tree t;
	t.insert(50);
	t.insert(40);
	return 0;
}
