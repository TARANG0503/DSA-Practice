/*
 * Middle of a linked list
 */
#include "iostream"
using namespace std;
class Node{
public:
    int val;
    Node*next;
    Node(int value){
        val = value;
         
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
        if(size==0){
            head =tail = temp;
        }else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void print(){
        Node *temp= head;
        while (temp!=NULL){
            cout << temp->val<< " ";
            temp  =temp->next;
        }
        cout << endl;
    }

    void mid(){
        Node *slow = head;
        Node *fast = head->next;
        while ( fast != NULL && fast->next!=tail->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        cout<< slow->val;
    }
};
int main(){
    LinkedList *list =  new LinkedList();
    list->add(10);
    list->add(120);
    list->add(150);
    list->add(130);
    list->add(150);

    list->mid();
}