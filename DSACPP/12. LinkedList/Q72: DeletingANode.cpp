/*
 * Deleting a node from a linked list
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
        head =tail= NULL;
        size = 0;
    }

    void add(int val){
        Node *temp = new Node(val);
        if(size == 0){
            head = tail = temp;
        }else{
            tail->next = temp;
            tail= temp;
        }
        size++;
    }

    void print() const{
        Node *temp = head;
        while (temp != tail->next){
            cout << temp->val << " ";
            temp = temp->next;
        }
    }

    void addAt(int index, int val){
        if(index ==size){
            add(val);
        } else if(index>size || index<0){
            return;
        }else{
            Node *temp = head;
            int counter =0;
            while(counter<index-1){
                temp = temp->next;
                counter++;
            }
            Node *temp2 = new Node(val);
            temp2->next = temp->next;
            temp->next = temp2;
        }
    }

    int get(int index){
        if(index<0 || index>size){
            return -1;
        }
        Node *temp = head;
        int counter= 0;
        while(counter<index){
            temp = temp->next;
            counter++;
        }
        return temp->val;
    }

    void removeAt(int index){
        if(index==0){
            head = head->next;
        }else if(index ==size-1){
            Node *temp = head;
            int counter =0;
            while (counter<index-1){
                temp = temp->next;
                counter++;
            }
            tail = temp;
        }else if(index<0 || index>=size){
            return;
        }else{
            Node *temp = head;
            int counter = 0;
            while(counter<index-1){
                temp = temp->next;
                counter++;
            }
            temp->next = (temp->next)->next;
        }
    }
};
int main(){
    LinkedList *list = new LinkedList();
    list->add(10);
    list->add(130);
    list->add(1340);
    list->add(210);
    list->add(104);
    list->add(240);
    list->removeAt(4);
    list->print();
}