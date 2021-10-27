/*
Problem Statement: Eliminate duplicates from LL
Problem Level: EASY
Problem Description:
You have been given a singly linked list of integers where the elements are sorted in ascending order.
Write a function that removes the consecutive duplicate values such that the given list only contains unique elements and returns the head to the updated list.
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
        size = 0;
        head = tail = NULL;
    }

    void add(int val){
        Node *temp = new Node(val);
        if(size==0){
            head =tail = temp;
        }else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void print(){
        Node *temp =head;
        while(temp!=tail->next){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void eliminateDuplicate(){
        Node *temp = head;
        while(temp->next!=tail->next){
            if(temp->val == (temp->next)->val){
                temp->next = (temp->next)->next;
                size--;
            }else {
                temp = temp->next;
            }
        }
    }
};
int main(){
    LinkedList *list = new LinkedList();
    list->add(1);
    list->add(1);
    list->add(1);
    list->add(1);
    list->add(1);
    list->add(12);
    list->add(12);
    list->add(12);
    list->add(12);
    list->add(12);
    list->add(13);
    list->add(13);
    list->add(13);
    list->add(13);
    list->add(14);
    list->add(14);
    list->add(14);
    list->add(14);
    list->print();
    list->eliminateDuplicate();
    list->print();
}