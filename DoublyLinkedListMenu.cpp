#include <iostream>

using namespace std;
struct Node{
    int marks;
    Node *next;
    Node *prev;
}*NewNode,*temp,*head,*tail,*res,*prv;

int count = 0;

Node* new_node(int m)
{
    NewNode = new Node();
   // struct Node* NewNode = struct(Node*)malloc(sizeof(struct Node));
    NewNode->marks = m;
    NewNode->prev = NULL;
    NewNode->next = NULL;
    return NewNode;
}
void insert_beg(Node *nexptr)
{

    if(head == NULL)
    {
        head=tail = nexptr;
    }
    else
    {
        head->prev=nexptr;
        nexptr->next=head;
        head=nexptr;
    }
    
   

}
void insert_end(Node *nexptr)
{
    if(head == NULL)
    {
        head=tail= nexptr;
       
    }
    else
    {
        tail->next=nexptr;
        nexptr->prev=tail;
        tail=nexptr;
    }
}
void insert_at_position(Node *nexptr, int pos)
{
    if(pos<1 || pos> count+1)
    {
        cout<<"Invalid Position"<<endl;
    }
    else if(pos==1)
    {
        insert_beg(res);
    }
    else if(pos>count)
    {
        insert_end(res);
    }
    else
    {
        if(head==NULL)
        {
           head = nexptr;
        }
        else
        {
            temp=head;
            for(int i=1;i<pos-1;i++)
            {
              //  prv=temp;
                temp=temp->next;
                /*temp->next=nxtptr;
                (temp->next)->prev=nxtptr;*/
            }
            nexptr->prev=temp;;
            nexptr->next=temp->next;
            temp->next=nexptr;
            (nexptr->next)->prev = nexptr;
        }
    }
}
void delete_beg(Node *hd)
{
    if(hd==NULL)
    {
        cout<<"List is Empty !"<<endl;
    }
    else
    {
     temp=hd;
     cout<<"node deleted "<<temp->marks<<endl;
     head = temp->next;
    }
}
void Result(Node *nexptr)
{
    while(nexptr !=NULL)
    {
        cout<<nexptr->marks<<" stored at address "<<nexptr<<"next :"<<nexptr->next<<"previous : "<<nexptr->prev<<endl;
        nexptr=nexptr->next;
    }
}


int main()
{
    
   head = NULL;
    int M;
    char choice = 'y';
    while(choice =='y'||choice =='Y')
    {
        int chm, option;
        cout<<"Main Menu"<<endl<<endl;
        cout<<"1. Insertion"<<endl;
        cout<<"2. Deletion"<<endl;
        cout<<"3. Searching "<<endl;
        cout<<"Enter your Choice : ";
        cin>>chm;
        
        switch(chm)
        {
            case 1:
                cout<<"Insertion Menu"<<endl<<endl;
                cout<<"1. Begining"<<endl;
                cout<<"2. End"<<endl;
                cout<<"3. Position"<<endl;
                cout<<"4. Sorted Insertion"<<endl;
                cout<<"Enter Choice of Insertion : ";
                cin>>option;

                cout<<"Enter Marks : ";
                cin>>M;
               res = new_node(M);
                if(res != NULL)
                {
                    cout<<"\n New Node Created"<<endl;
                }

                switch(option)
                {
                    case 1:
                        insert_beg(res);
                        count++;
                        cout<<"Count is : "<<count<<endl;
                        break;
                    case 2:
                        insert_end(res);
                        count++;
                        cout<<"Count is : "<<count<<endl;
                        break;
                    case 3:
                        int position;
                        cout<<"Enter position : ";
                        cin>>position;
                        insert_at_position(res,position);
                        count++;
                        cout<<"Count is : "<<count<<endl;
                        break;
                    
                    default:
                        break;
                }
                cout<<"\nList is: ";
                Result(head);
                break;
                case 2:
                cout<<"Deletion Menu"<<endl<<endl;
                cout<<"1. Begining"<<endl;
                cout<<"2. End"<<endl;
                cout<<"3. Position"<<endl;
                cout<<"Enter Choice of Deletion : ";
                cin>>option;
                switch(option)
                {
                    case 1:
                        delete_beg(head);
                        count--;
                        cout<<"Count is : "<<count<<endl;
                        break;
                    case 2:
                        delete_end(head);
                        count--;
                        cout<<"Count is : "<<count<<endl;
                        break;
                    case 3:
                       int p;
                       cout<<"Enter Position : ";
                       cin>>p;
                       delete_at_position(head,p);
                       count--;
                       cout<<"Count is : "<<count<<endl;
                       break;
                    default:
                        break;
                }
                cout<<"\nList is: ";
                Result(head);
                break;
           
                
            default:
                break;
        }
        cout<<"\n Want to continue (Y/N) : ";
        cin>>choice;
    }

    return 0;
}

