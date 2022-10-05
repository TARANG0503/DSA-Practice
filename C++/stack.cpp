#include<iostream>
#define max 5
using namespace std;
class stack{
	public:
		int data;
		int top;
		int A[max];
		stack()
		{
			top=-1;
		}
		void push(int data);
		void pop();
		int peek();
		void print();
		stack reverse();
		bool empty();
		void recureverse(int size);
		void bottom(int data,int size);
		int maxt();
		int middle(int size);
};
int i=0;
void stack::bottom(int data,int size)
{
    this->A[size-i]=data;
    i++;
    this->top++;
    return;
}
bool stack::empty()
{
	if(top==-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void stack::push(int data)
{
	if(top==max-1)
	{
		cout<<"Not Possible";
		return;
	}
	else
	{
		top++;
		this->A[top]=data;
	}
}
void stack::pop()
{
	if(top==-1)
	{
		cout<<"Empty";
		return;
	}
	top--;
	return;
}
int stack::peek()
{
	if(top==-1)
	{
		cout<<"empty";
		return -1;
	}
	return(A[top]);
}
void stack::print()
{
	if(top==-1)
	{
		cout<<"empty";
		return;
	}
	for(int i=top;i!=-1;i--)
	{
		cout<<A[i];
	}
	return;
}
stack stack::reverse()  //By temporary stack;
{
	stack s2;
	while(this->top!=-1)
	{
		s2.push(this->A[this->top]);
		this->pop();
	}
	return s2;
}
void stack::recureverse(int size) //by recursive reverse;
{
	if(this->top==-1)
	{
		return;
	}
	int data=this->A[this->top];
	this->pop();
	recureverse(size);
	bottom(data,size);
}
int stack::maxt() //max elemet;
{
	int i=this->A[this->top];
	for(int j=top-1;j!=-1;j--)
	{
		if(i<this->A[j])
		{
			i=this->A[j];
		}
	}
	return i;
}
int stack::middle(int size)
{
		return this->A[size/2];
}
int main()
{
	
}
