/*
 * Stacks implementation using arrays
 */
#include "iostream"
using namespace std;
class Stack{
    int *arr;
    int nextIndex;
    int capacity;
public:
    Stack(int fixedSize = 5){
        arr = new int[fixedSize];
        nextIndex = 0;
        capacity = fixedSize;
    }
    void push(int val){
        if(nextIndex==capacity){
            cout << " Stack is full. ";
            return;
        }
        arr[nextIndex] = val;
        nextIndex++;
    }
    int size(){
        return nextIndex;
    }
    int pop(){
        if(nextIndex==0) return -1;
        nextIndex--;
        return arr[nextIndex];
    }
    bool isEmpty(){
        return nextIndex==0;
    }
    int top(){
        if(nextIndex==0) return -1;
        return arr[nextIndex-1];
    }

};
int main(){
    Stack *s = new Stack(5);
    cout<<s->isEmpty()<<endl;
    s->push(1);
    s->push(2);
    cout << s->pop()<<endl;
    s->push(3);
    cout << s->top() << endl;
    s->push(2);
}