/*
 * Implementation of Stack using a LinkedList
 */
#include "iostream"
using namespace std;
class Node{
public:
    int val;
    Node*next;
    Node(int value){
        val = value;
        next = NULL;
    }
};
class Stack{
    Node *head;
    int size;
public:
    Stack(){
        head = NULL;
        size = 0;
    }

    void push(int val){
        if(head==NULL){
            head = new Node(val);
        }else{
            Node *temp = new Node(val);
            temp->next = head;
            head = temp;
        }
        size++;
    }

    int pop(){
        if(head == NULL){
            cout << "Stack is empty. " << endl;
            return -1;
        }else{
            int val = head->val;
            Node *temp = head;
            head = head->next;
            delete temp;
            return val;
        }
    }

    int getSize(){
        return size;
    }

    int top(){
        if(head==NULL){
            cout << "Stack is empty. " << endl;
            return -1;
        }else{
            return head->val;
        }
    }

    bool isEmpty(){
        return head == NULL;
    }
};
int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout << s.getSize()<<endl;
    cout << s.pop() << endl;
    cout <<s.top() <<endl;
    s.push(100);
    cout << s.pop() << endl;
}