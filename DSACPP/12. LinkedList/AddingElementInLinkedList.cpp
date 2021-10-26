//
// Create a Linked List with function to add values in a linked list
//
#include "iostream"
using namespace std;
class Node{
public:
    int val;
    Node* next;

    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};
class LinkedList{
public:
    Node *head;
    Node *tail;
    int size;

    LinkedList(){
        this->head = NULL;
        this->size = 0;
        this->tail = NULL;
    }

    void add(int val){
        if(size == 0){
            tail = new Node(val);
            head = tail;
            size++;
        }else{
            tail->next = new Node(val);
            tail = tail->next;
            size++;
        }
    }

};

int main(){
    LinkedList *list = new LinkedList();
    list->add(10);
    list->add(10);
    list->add(20);
    list->add(10);
    list->add(10);
    cout << list->size<<endl;
    Node *temp = list->head;
    while(temp != NULL){
        cout << temp->val << endl;
        temp = temp->next;
    }
}