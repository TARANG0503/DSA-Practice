/*
Chapter Assignment
Problem Statement: Even after Odd LinkedList
Problem Level: MEDIUM
Problem Description:
For a given singly linked list of integers, arrange the elements such that all the even numbers are placed after the odd numbers. The relative order of the odd and even terms should remain unchanged.
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
*/
#include "iostream"
using namespace std;
class Node{
public:
    int val;
    Node *next;
    Node(){
    }
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
        head=tail= NULL;
        size = 0;
    }
    void add(int val){
        Node *temp = new Node(val);
        if(size == 0){
            head = tail =temp;
        }else{
            tail->next =temp;
            tail = temp;
        }
        size++;
    }
    void print(){
        Node *temp = head;
        while(temp!=NULL){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
void oddEven(Node *head){
    Node *oddH = NULL;
    Node *oddT = NULL;
    Node *evenH  =NULL;
    Node *evenT = NULL;
    while(head!= NULL){
        if(head->val %2 == 0){
            if(evenH==NULL){
              evenH = evenT = head;
            }else{
                evenT->next = head;
                evenT = evenT->next;
            }
        }else{
            if(oddH == NULL){
                oddH = oddT = head;
            }else{
                oddT->next = head;
                oddT = oddT->next;
            }
        }
        head = head->next;
    }
    oddT->next = evenH;
    evenT->next = NULL;
}
int main(){
    LinkedList *list  =  new LinkedList();
    list->add(1);
    list->add(4);
    list->add(5);
    list->add(2);
    oddEven(list->head);
    list->print();
}