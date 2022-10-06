#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

node* head=NULL;
node *create()
{
    int data;
    cout << "Enter element :";
    cin >> data;

    node *newnode = (node *)malloc(sizeof(node));
    newnode->data=data;
    newnode->next = NULL;

    if (head == NULL)
        head=newnode;
    else
    {
        node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }

    cout << "node inserted";
    cout << endl;
    return head;    
}

node* insertatbeg()
{
    int data;
    cout<<"Enter element:";
    cin>>data;

    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=head;
    head=newnode;

    return head;
}

node* insertatend()
{
    int data;
    cout<<"Enter element:";
    cin>>data;

    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;

    node* ptr=head; 
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=newnode;

    return head;
}

node* insertatindex()
{
    int index,data;
    cout<<"Enter index :"<<endl;
    cin>>index;
    cout<<"Enter data :";
    cin>>data;

    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=data;

    node* ptr=head;
    for(int i=0;i<index-1;i++)
    {
        ptr=ptr->next;
    }
    newnode->next=ptr->next;
    ptr->next=newnode;

    return  head;
}

node* deleteatbeg()
{
    node* q=head;
    head=head->next;
    free(q);

    return head;
}

node* deleteatend()
{
    node* p=head;
    node*q=head->next;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);

    return head;
}

node* deleteatindex()
{
    int index;
    cout<<"Enter index :";
    cin>>index;

    node* p=head;
    node* q=head->next;

    for(int i=0;i<index-1;i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);

    return head;
}

void display()
{
    cout<<endl;
    node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

void findanddelete()
{
    int datav,count=0;
    cout<<"Enter data to search :";
    cin>>datav;

    node* p=head;
    while(p!=NULL)
    {
        if(p->data==datav)
        {
            cout<<"found at :"<<count<<" ";
        }
        p=p->next;
        count++;
    }
}

int main()
{
    int ch;

    while (100)
    {

        cout<<endl<<"Select :\n1.Create\n2.Display\n3.InsertAtBeg\n4.Insetatend\n5.Insertatindex\n6.Deleteatbeg\n7.Deleteatend\n8.Deleteatindex\n9.find&delete"<<endl;
        cout << "Enter choice :";
        cin >> ch;
        switch (ch)
        {
        case 1:create();break;
        case 2:display();break;
        case 3:insertatbeg();break;
        case 4:insertatend();break;
        case 5:insertatindex();break;
        case 6:deleteatbeg();break;
        case 7:deleteatend();break;
        case 8:deleteatindex();break;
        case 9:findanddelete();break;
        }
    }
}