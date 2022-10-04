#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
node *head;

int length(node *head)
{
    int count = 0;
    node *ptr = head;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        count++;
    }
    return count;
}

void push(int data)
{
    // create a new linked list node from the heap
    node *newnode = (node *)malloc(1 * sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    node *p2 = head;
    while (p2->next != NULL)
    {
        p2 = p2->next;
    }
    p2->next = newnode;
}

node *evenAfterOdd(node *head)
{
    node *even = new node(0);
    node *etail = even;

    node *odd = new node(0);
    node *otail = odd;

    while (head)
    {

        if (head->data % 2 == 0)
        {
            etail->next = head;
            etail = head;
            head = head->next;
            etail->next = NULL;
        }
        else
        {
            otail->next = head;
            otail = head;
            head = head->next;
            otail->next = NULL;
        }
    }
    otail->next = even->next;
    return odd->next;
}

// second method

node *evenafterodd(node *head)
{
    node *evenhead = NULL, *eventail = NULL, *oddhead = NULL, *oddtail = NULL;
    if (head == NULL)
    {
        return head;
    }
    while (head != NULL)
    {
        if (head->data % 2 == 0)
        {
            if (evenhead == NULL)
            {
                evenhead = head;
                eventail = head;
            }
            else
            {
                eventail->next = head;
                eventail = eventail->next;
            }
        }
        else
        {
            if (oddhead == NULL)
            {
                oddhead = head;
                oddtail = head;
            }
            else
            {
                oddtail->next = head;
                oddtail = oddtail->next;
            }
        }
        head = head->next;
    }
    if (oddhead == NULL)
    {
        return evenhead;
    }
    else
    {
        oddtail->next = evenhead;
    }
    if (evenhead != NULL)
    {
        eventail->next = NULL;
    }
    return oddhead;
}
void display(node *head)
{
    node *p2 = head;
    while (p2 != NULL)
    {
        cout << "->" << p2->data;
        p2 = p2->next;
    }
}
int main()
{
    int n, data;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        push(data);
    }
    evenAfterOdd(head);
    display(head);
}