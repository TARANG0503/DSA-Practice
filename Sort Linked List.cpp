#include <iostream>

using namespace std;



class node
{
    public:

  int data;
  node *next;

};


void print (node * head)
{

  while (head != NULL)
    {

      cout << head->data << " --> ";
      // update head jab tak NULL na aa jae
      head = head->next;
    }

  cout << "NULL" << endl;

}


void createLinkList(node* &head, int num)
{
    node* temp = NULL;
    
    for(int i = 0; i < num; i++)
    {
        node* new_node = new node();
        
        cin >> new_node -> data;
        
        new_node -> next = NULL;
        
        
        if(head == NULL)
        {
            head = new_node;
            temp = head;
        }
        
        else
        {
            temp -> next = new_node;
            temp = new_node;
        }
        
    }
    
    
}



void selectionSort(node* head)
{
    node* temp = head;
 
    // Traverse the List
    while (temp) 
    {
        node* min = temp;
        node* r = temp->next;
        
        // Traverse the unsorted sublist
        while (r) 
        {
            // agar data bada hua toh aage badho
            if (min->data > r->data)
            min = r;
            r = r->next;
        }
        
        // Swap Data krro
        int x = temp->data;
        temp->data = min->data;
        min->data = x;
        
        
        temp = temp->next;
    }
}

/*
void swap(node *a, node *b) 
{ 
    int temp = a->data; 
    a->data = b->data; 
    b->data = temp; 
} 
*/

node* swap(node* ptr1, node* ptr2)
{
    node* tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}


void bubbleSort(node* head, int count)
{
    node* h;
    int i, j, swapped;
  
    for (i = 0; i <= count; i++)
    {
        h = head;
        swapped = 0;
        
        for (j = 0; j < count - i - 1; j++) 
        {
            node* p1 = h;
            node* p2 = p1->next;
  
            if (p1->data > p2->data)
            {
  
                // update the link after swapping 
                h = swap(p1, p2);
                swapped = 1;
            }
            
            
            // nhi toh aage badho
            h = h->next;
        }
  
        // break if the loop ended without any swap 
        if (swapped == 0)
        break;
    }
}

int main()
{
    node* head = NULL;
    
    int n;
    cout << "Enter the number of element in linked list: ";
    cin >> n;
    
    createLinkList(head, n);
    cout << "Linked list: ";
    print(head);
    cout << endl;
    
    
    selectionSort(head);
    cout << "After selection sorting: ";
    print(head);
    cout << endl;
    
    bubbleSort(head,n);
    cout << "After bubble sorting: ";
    print(head);
    cout << endl;
    
    

    return 0;
}

/*

OUTPUT
Enter the number of element in linked list: 6
7 10 5 20 6 2
Linked list: 7 --> 10 --> 5 --> 20 --> 6 --> 2 --> NULL

After selection sorting: 2 --> 5 --> 6 --> 7 --> 10 --> 20 --> NULL

After bubble sorting: 2 --> 5 --> 6 --> 7 --> 10 --> 20 --> NULL

*/
