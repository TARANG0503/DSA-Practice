/*
 * Printing ith index of a linked list
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
        head = tail =NULL;
    }
    void add(int val){
        Node *temp = new Node(val);
        if(size==0){
            head = tail = temp;
        }else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void print() const{
        Node *temp = head;
        while(temp != tail->next){
            cout <<temp->val;
            temp = temp->next;
        }
    }

    int get(int index){
        if(index>size || index<0){
            return -1;
        }
        int counter = 0;
        Node *temp = head;
        while(counter!=index){
            temp = temp->next;
            counter++;
        }
        return temp->val;
    }
};

int main(){
    LinkedList *list = new LinkedList();
    list->add(10);
    list->add(140);
    list->add(104);
    list->add(150);
    list->add(160);
    cout <<list->get(3);


}