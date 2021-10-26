/*
 * Adding a node at ith index
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
            cout<<temp->val << " ";
            temp = temp->next;
        }
    }

    int get(int index){
        if(index>size || index<0){
            return -1;
        }
        Node *temp = head;
        int counter = 0;
        while(counter!=index){
            temp = temp->next;
            counter++;
        }
        int val = temp->val;
        return val;
    }

    void addAt(int index, int val){
        if(index==size){
            add(val);
        }else if(index>size || index <0){
            return;
        }else{
            Node *temp = head;
            int counter = 0;
            while(counter<index-1){
                temp = temp->next;
                counter++;
            }
            Node *main = new Node(val);
            main->next = temp->next;
            temp->next = main;
        }
    }
};
int main(){
    LinkedList *list = new LinkedList();
    list->add(10);
    list->add(130);
    list->add(1230);
    list->add(103);
    list->add(140);
    list->addAt(3,500);
    list->print();
}