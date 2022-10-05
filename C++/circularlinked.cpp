#include<iostream>
using namespace std;
class circle{
	public:
		int data;
		circle *next;
		void push(int data);
		void pop();
		void print();
};
circle *head=NULL;
void circle::push(int data)
{
	circle *temp=new circle();
	temp->data=data;
	temp->next=head;
	if(head==NULL)
	{
		head=temp;
		head->next=head;
		return;
	}
	circle *t=new circle();
	t=head;
	while(t->next!=head)
	{
		t=t->next;
	}
	t->next=temp;
	return;
}
void circle::pop()
{
	circle *temp=new circle();
	temp=head;
	circle *t;
	t=temp;
	while(temp->next!=head)
	{
		t=temp;
		temp=temp->next;
	}
	t->next=head;
}
void circle::print()
{
	circle *temp=new circle();
	temp=head;
	while(temp->next!=head)
	{
		cout<<temp->data;
		temp=temp->next;
	}
	cout<<temp->data;
	return;
}
int main()
{
	circle c;
	c.push(30);
    c.push(40);
    c.print();
}
