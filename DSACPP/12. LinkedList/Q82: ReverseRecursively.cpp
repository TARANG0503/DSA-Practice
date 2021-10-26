/*
 * Reverse Linked List Recursively
 */
#include "iostream"
using namespace std;
class Node{
public:
    int val;
    Node *next;
    Node(int value){
        next  = NULL;
        val = value;
    }
};
class LinkedList{
public:
    Node *head;
    Node *tail;
    int size;

    void add(int val){
        Node*temp = new Node(val);
        if(size==0){
            head = tail = temp;
        }else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void print(){
        Node *temp  = head;
        while (temp!=NULL){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
Node* reverse(Node* prev, Node* current){
    if(current==NULL) return prev;
    Node *temp = current;
    current = current->next;
    temp->next = prev;
    prev = temp;
    return reverse(prev,current);
}
int main(){
    LinkedList *list = new LinkedList();
    list->add(10);
    list->add(140);
    list->add(103);
    list->add(4103);
    list->add(1035);
    Node *temp = reverse(NULL,list->head);
    while (temp!=NULL){
        cout << temp->val << " ";
        temp=temp->next;
    }
    cout << endl;
}