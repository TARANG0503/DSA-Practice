/*
 * Reverse A linked list iterative
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
        head = tail = NULL;
        size = 0;
    }

    void add(int val){
        Node *temp = new Node(val);
        if(size == 0){
            head =tail = temp;
        }else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    void print(){
        Node *temp = head;
        while(temp!= tail->next){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout<< endl;
    }
    void reverse(){
        if(head==NULL || head->next==NULL) return;
        Node *prev =NULL;
        tail = head;
        Node* current = head;
        Node *nexT = head->next;
        while(nexT != NULL){
            current->next = prev;
            prev = current;
            current = nexT;
            nexT = nexT->next;
        }
        current->next = prev;
        head = current;
    }
};
int main(){
    LinkedList *list = new LinkedList();
    list->add(1);
    list->add(2);
    list->add(3);
    list->add(4);
    list->reverse();
    list->print();

}