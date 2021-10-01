#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node * next;
};

struct Node * front = NULL;
struct Node * rear = NULL;


int isFull(){
    struct Node * n = (struct Node*)malloc(sizeof(struct Node));
    if(n==NULL){
        return 1;
    }else{
        return 0;
    }
}

int isEmpty(){
    if(front==NULL){
        return 1;
    }else{
        return 0;
    }
}


void enqueueR(int val){

    if(isFull()){
        cout<<"Queue is full can't enqueue"<<endl;
    }else{
        struct Node * n = (struct Node*)malloc(sizeof(struct Node));
        n->data = val;
        n->next = NULL;

        if(front == NULL){
            front = n;
            rear = n;
        }else{
            rear->next = n;
            rear = n;
        }
    }
}

void enqueueF(int val){

    if(isFull()){
        cout<<"Queue is full can't enqueue"<<endl;
    }else{
        struct Node * n = (struct Node*)malloc(sizeof(struct Node));
        n->data = val;
        n->next = front;
        front = n;

        if(rear == NULL){
            rear = n;
        }
    }
}

int dequeueF(){
    if(isEmpty()){
        cout<<"Queue is empty can;t dequeue"<<endl;
        return -1;
    }else{
        struct Node * n = front;
        front = front->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int dequeueR(){
    if(isEmpty()){
        cout<<"Queue is empty can;t dequeue"<<endl;
        return -1;
    }else{
        struct Node * n = front;

        while(n->next->next!=NULL){
            n = n->next;
        }

        int val = n->next->data;
        free(n->next);
        n->next = NULL;
        rear = n;

        return val;
    }
}


void display(struct Node * front){
    while(front!=NULL){
        cout<<front->data<<endl;
        front = front->next;
    }
}

int main(){

    enqueueR(1);
    enqueueR(2);
    enqueueR(3);
    enqueueR(4);

    display(front);
    cout<<endl;

    enqueueF(60);
    enqueueF(70);

    
    display(front);
    cout<<endl;

    dequeueR();
    dequeueR();

 
    display(front);
    cout<<endl;

    enqueueR(100);


 
    display(front);
    cout<<endl;


    return 0;
}
