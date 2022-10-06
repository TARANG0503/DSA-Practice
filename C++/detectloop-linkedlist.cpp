#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    int flag;
};

// void print(node *head)
// {
//     node *ptr = head;
//     while (ptr != NULL)
//     {
//         cout << ptr->data << " ";
//         ptr = ptr->next;
//     }
// }

void check(node* head,int n)
{
    node* p=head;
    while(p!=NULL)
    {
        if(p->flag==1)
        {
            cout<<"loop";
            break;
        }
        else
        {
            p->flag=1;
        }
        p=p->next;
    }
}

int main()
{
    node *head = (node *)malloc(sizeof(node));
    node *one = (node *)malloc(sizeof(node));
    node *two = (node *)malloc(sizeof(node));
    node *inserted = (node *)malloc(sizeof(node));

    head->data = 1;
    head->next = one;

    one->data = 2;
    one->next = two;

    one->next = inserted;
    inserted->data = 10;
    inserted->next = head;

    two->data = 3;
    two->next = NULL;

    // print(head);
    check(head,3);
    return 0;
}