//@soumyaagr427

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution
{
    public:
    Node* pairWiseSwap(struct Node* head) 
    {
        //corner cases if empty or one node list given
        if (head==NULL || head->next==NULL)
            return head;
            
        
        
        Node *prev=head;
        Node *curr=head->next;
        
        head=curr;
        
        while(1)
        {
            Node* after = curr->next;
            curr->next=prev;
            
            //if there is three or two nodes only
          
            if (after == NULL || after->next == NULL) 
            { 
                prev->next = after;
                break;
            }
            
            prev->next=after->next;
            
            prev=after;
            curr=prev->next;
            
        }
        
        return head;
        
    }
};

void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
}

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int data;
		cin>>data;
		struct Node *head = new Node(data);
		struct Node *tail = head;
		map<Node*, int> mp;
		mp[head] = head->data;
		for (int i = 0; i<n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
			mp[tail] = tail->data;
		}
		struct Node *failure = new Node(-1);
		Solution ob;
		head = ob.pairWiseSwap(head);
		int flag = 0;
		struct Node *temp = head;
		while(temp){
		    if(mp[temp] != temp->data){
		        flag = 1;
		        break;
		    }
		    temp = temp->next;
		}
		if(flag)
		    printList(failure);
		else
		    printList(head);
	}
	return 0; 
}
