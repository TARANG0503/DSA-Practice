/*
 * Merging two sorted Linked List
 */
#include "iostream"
using namespace std;
class Node{
public:
    int val;
    Node* next;
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
        head = tail =NULL;
        size = 0;
    }
    void add(int val){
        Node *temp = new Node(val);
        if(size ==0){
            head = tail = temp;
        }else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

};
Node* merge(Node* n1, Node* n2){
    LinkedList *main = new LinkedList();
    while (n1!= NULL || n2 != NULL){
        if(n1==NULL){
            main->add(n2->val);
            n2= n2->next;
        }else if(n2==NULL){
            main->add(n1->val);
            n1 = n1->next;
        }else if(n1->val>n2->val){
            main->add(n2->val);
            n2 = n2->next;
        }else{
            main->add(n1->val);
            n1 = n1->next;
        }
    }
    return main->head;
}
int main(){
    LinkedList *list1 = new LinkedList();
    LinkedList *list2 = new LinkedList();
    list1->add(1);
    list1->add(2);
    list1->add(2);
    list2->add(2);
    list2->add(3);
    list2->add(4);
    list2->add(4);
    Node *head = merge(list1->head,list2->head);
    while(head!=NULL){
        cout << head->val<<" ";
        head = head->next;
    }



}