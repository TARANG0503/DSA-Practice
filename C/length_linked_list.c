#include<iostream>
using namespace std;
struct node
{
           int data;
           node *next;
};
node* insert_node(node *start,int x)
{
           node *temp=new node;
           temp->data=x;
           temp->next=NULL;
           if(start==NULL)
                      return temp;
           node *ptr=start;
           while(ptr->next!=NULL)
           {
                      ptr=ptr->next;
           }
           ptr->next=temp;
           return start;
}
void display(node *start)
{
           node *temp=start;
           while(temp!=NULL)
           {
                      cout<<temp->data<<" ";
                      temp=temp->next;
           }
}
void length(node *start)
{
           int c=1;
           node *temp=start;
           while(temp->next!=NULL)
           {
                      temp=temp->next;
                      c++;
           }
           cout<<"\nLength of the given linked list:"<<c;
}
int main()
{
           node *sample=NULL;
           sample=insert_node(sample,10);
           sample=insert_node(sample,20);
           sample=insert_node(sample,30);
           sample=insert_node(sample,40);
           sample=insert_node(sample,50);
           display(sample);
           length(sample);
           return 0;
}
