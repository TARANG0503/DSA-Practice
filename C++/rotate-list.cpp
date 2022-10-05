class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL||k==0) return head;
        ListNode *temp=head;
        int count=1;
        while(temp->next!=NULL){
            temp=temp->next;
            count++;
        }
        temp->next=head;
        int len=k%count;
        k=count-len;
        while(k--){
            temp=temp->next;
        }
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};
