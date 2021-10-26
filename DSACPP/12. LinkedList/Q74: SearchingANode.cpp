/*
 * Searching for a node in a linked list with
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
        head=tail=NULL;
    }

    void add(int val){
        Node *temp=new Node(val);
        if(size ==0){
            head=tail=temp;
        }else{
            tail->next = temp;
            tail= temp;
        }
        size++;
    }

    void print(){
        Node *temp = head;
        while(temp!=tail->next){
            cout << temp->val <<" ";
            temp = temp->next;
        }
        cout << endl;
    }

    int search(int val){
        Node *temp = head;
        int counter = 0;
        while (temp!=tail->next){
            if(temp->val == val) return counter;
            counter++;
            temp = temp->next;
        }
        return -1;
    }
};
int main(){
    LinkedList *list = new LinkedList();
    list->add(40);
    list->add(450);
    list->add(404);
    list->add(240);
    list->add(340);
    list->add(420);
    list->add(406);
    cout << list->search(420)<<endl;
}