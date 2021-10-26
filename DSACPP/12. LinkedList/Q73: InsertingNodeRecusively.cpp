/*
 * Insert a node into a linked list recursively
 */
#include "iostream"
using namespace std;
class Node{
public:
    int val;
    Node *next;
    Node(int value){
        val =value;
        next = NULL;
    }
};
class LinkedList{
public:
    Node *head;
    Node *tail;
    int size;
    LinkedList(){
        size = 0;
        head = tail = NULL;
    }

    void add(int val){
        Node *temp = new Node(val);
        if(size==0){
            head=tail=temp;
        }else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void print(){
        Node *temp = head;
        while(temp!= tail->next){
            cout << temp->val <<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    void addAtR(int index, int val, Node *temp){
        if(index<0) return;
        if(size==0 || index==size) {
            add(val);
            return;
        }
        else if(index==0 && temp==head){
            Node *temp2 = new Node(val);
            temp2->next = temp;
            head = temp2;
            size++;
            return;
        }else if(index == 1){
            Node *temp2 = new Node(val);
            temp2->next = temp->next;
            temp->next = temp2;
            size++;
            return;
        }
        addAtR(--index,val,temp->next);
    }
};

int main(){
    LinkedList *list  = new LinkedList();
    list->add(10);
    list->add(10);
    list->add(10);
    list->addAtR(0,20,list->head);
    list->addAtR(4,20,list->head);
    list->addAtR(2,200,list->head);
    list->add(10);
    list->print();
}