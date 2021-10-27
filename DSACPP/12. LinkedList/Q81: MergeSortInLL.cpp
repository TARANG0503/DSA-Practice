/*
 * Sorting a Linked List using merge sort
 */
#include "iostream"
using namespace std;
class Node{
public:
    int val;
    Node *next;
    Node(int value){
        val = value;
        next = NULL;
    }
};
class LinkedList{
public:
    Node *head;
    Node *tail;
    int size;
    LinkedList(){
        head =tail = NULL;
        size = 0;
    }
    void add(int val){
        Node *temp = new Node(val);
        if(size==0){
            head = tail  =temp;
        }else{
            tail->next = temp;
            tail =temp;
        }
        size++;
    }
    void print(){
        Node *temp = head;
        while(temp!= NULL){
            cout << temp->val<< " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
Node* mergeSort(Node* head, Node *tail){
    if(head == NULL || head->next == NULL) return head;
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast =  fast->next->next;
    }
    Node *h2 = slow->next;
    slow->next = NULL;
    Node *head1 = mergeSort(head,slow);
    Node *head2 = mergeSort(h2, tail);
    LinkedList *list = new LinkedList();
    while (head1!=NULL || head2!= NULL){
        if(head2 == NULL){
            list->add(head1->val);
            head1 = head1->next;
        } else if(head1 == NULL){
            list->add(head2->val);
            head2 = head2->next;
        }else if(head1->val > head2->val){
            list->add(head2->val);
            head2 = head2->next;
        }else{
            list->add(head1->val);
            head1 =head1->next;
        }
    }
    return list->head;
}
int main(){
    LinkedList *list = new LinkedList();
    list->add(2);
    list->add(23);
    list->add(21);
    list->add(20);
    list->add(23);
    Node *head = mergeSort(list->head, list->tail);
    while (head != NULL){
        cout << head->val << " ";
        head = head->next;
    }

}