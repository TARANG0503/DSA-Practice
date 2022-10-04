/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return NULL;
        else
        {
            ListNode *p = head;
            ListNode *q = head->next;
            while(q)
            {
                if(q->val != p->val)
                {
                    p->next = q;
                    p = p->next;
                }
                q = q->next;
            }
            p->next = NULL;
            return head;
        }
    }
};