//@soumyaagr427

#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

class Solution
{
    public:

    struct node *reverse (struct node *head, int k)
    { 
        // same for reversing a list
        node* prev=NULL;
        node* curr=head;
        node* next;
       
       // counter to set for k nodes only
       int count=0;
       
       while(curr!=NULL & count<k)
       {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
       }
       
       //observe in output that when reserved next of head is linked to another group
       if(next!=NULL)
         head->next=reverse(curr,k);
       
       return prev;
    }
};


int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}
