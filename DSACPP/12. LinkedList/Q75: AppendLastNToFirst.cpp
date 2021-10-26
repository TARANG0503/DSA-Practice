/*
Problem Statement: AppendLastNToFirst
Problem Level: EASY
Problem Description:
You have been given a singly linked list of integers along with an integer 'N'.
Write a function to append the last 'N' nodes towards the front of the singly linked list and returns the new head to the list.
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
        head = tail = NULL;
        size =0;
    }

    void add(int val){
        Node *temp = new Node(val);
        if(size==0){
            head =tail=temp;
        }else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void print(){
        Node *temp  =head;
        while(temp!=tail->next){
            cout << temp->val << " ";
            temp= temp->next;
        }
        cout << endl;
    }

    void appendLastNToFirst(int n){
        if(n==0) return;
        Node *temp = head;
        while(temp->next!=tail) temp = temp->next;

        (temp->next)->next = head;
        head = temp->next;
        tail = temp;
        temp->next = NULL;
        appendLastNToFirst(--n);
    }
};
int main(){
    LinkedList *list =new LinkedList();
    list->add(10);
    list->add(20);
    list->add(30);
    list->add(40);
    list->add(50);
    list->add(60);
    list->print();
    list->appendLastNToFirst(3);
    list->print();
}