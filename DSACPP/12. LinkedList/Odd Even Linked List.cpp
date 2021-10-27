class Solution {
public:
    ListNode* oddEvenList(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
            return head;
            
        ListNode* odd = head;
        ListNode* node = head->next;
        ListNode* even = node;
        
        while(even != NULL && even->next != NULL)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        
        odd->next = node;
        return head;
    }
};
