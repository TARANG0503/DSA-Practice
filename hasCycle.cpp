// This program is to check to check whether a singly linked list has cycle in it, which means if last node is connected to any other node or not.

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
#define ll long long
#define sc ;
#define tc ll t sc cin >> t sc while (t--)
#define fast ios::sync_with_stdio(false)
#define spyder cin.tie(NULL)

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

bool hasCycle(Node *head)
{
    if (head == NULL)
        return false;
    Node *slow_ptr = head, *fast_ptr = head;
    while (fast_ptr && fast_ptr->next)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if (slow_ptr == fast_ptr)
            return true;
    }
    return false;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    Node *cycle = head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(50);
    head->next->next->next->next->next->next = cycle;
    if (hasCycle(head))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}