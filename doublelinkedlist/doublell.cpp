#include<iostream>
using namespace std;
class Node
{
	public:
		int data;
		Node* Next;
		Node* prev;
	Node(int d)
	{
		this->data=d;
		this->Next=NULL;
		this->prev=NULL;
		}	
};
void insertAthead(Node* &head,Node* &tail,int d)
{
	if(head==NULL)
	{
		Node* temp=new Node(d);
		head=temp;
		tail=temp;
	}
	else
	{
	Node* temp=new Node(d);
	temp->Next=head;
	head->prev=temp;
	head=temp;
	}
}
void insertAttail(Node* &tail,Node* &head,int d)
{
	if(tail==NULL)
	{
	    Node* temp=new Node(d);
		tail=temp;
		head=temp;	
	}
	else
	{
	Node* temp= new Node(d);
	tail->Next=temp;
	temp->prev=tail;
	tail=temp;
	}
}
void print(Node* &head)
{
	Node* temp= head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->Next;
	}
	cout<<endl;
}
void insertAtposition(Node* &head,Node* &tail,int position,int d)
{
	if(position==1)
	{
		insertAthead(head,tail,d);
		return;
	}
	Node* temp=head;
	int cnt=1;
	while(cnt<position-1)
	{
		Node* temp=head;
		cnt++;
	}
	if(temp!=NULL)
	{
		insertAttail(tail,head,d);
		return;
	}
	Node* Nodetoinsert=new Node(d);
	Nodetoinsert->Next=temp->Next;
	temp->Next->prev=Nodetoinsert;
	temp->Next=NULL;
}
void DelteNode(Node* &head,Node* &tail,int position)
{
if(position == 1)
    {
      Node* temp = head;
      head = head -> Next;
      temp->Next = NULL;
      delete temp;
    }
	else
	{
      Node* curr = head;
      Node* prev = NULL;
      int cnt = 1;
      
      while(cnt < position)
	  {
          prev = curr;
          curr = curr -> Next;
          cnt++;
      }
      if(curr -> Next == NULL)
	  {
        tail = prev;
      }
      prev->Next = curr->Next;
      curr->Next = NULL;
      delete curr;
    }
}

int getLenght(Node* &head)
{
	Node* temp=head;
	int len=0;
	while(temp!=NULL)
	{
		temp=temp->Next;
		len++;
	}
	return len;
}
int main()
{

	Node* head=NULL;
	Node* tail=NULL;
	print(head);
	insertAthead(head,tail,12);
	print(head);
	insertAttail(tail,head,8);
	print(head);
	insertAtposition(head,tail,3,10);
	print(head);
	DelteNode(head,tail,3);
	print(head);
	cout<<"Head:-"<<head->data<<endl;
	cout<<"Tail:-"<<tail->data<<endl;
}