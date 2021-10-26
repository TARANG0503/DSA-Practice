/*
 * Printing a linked list
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
        head =tail = NULL;
        size = 0;
    }

    void add(int val){
        Node *temp = new Node(val);
        if(size == 0){
            head = tail = temp;
        }else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void print(){
        Node *temp = head;
        while(temp != tail->next){
            cout << temp->val  << " ";
            temp = temp->next;
        }
    }
};

int main(){
    LinkedList *list = new LinkedList();
    list->add(10);
    list->add(20);
    list->add(30);
    list->add(10);
    list->print();
}