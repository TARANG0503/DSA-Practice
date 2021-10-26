/*
 * Dynamic Stack implementation using Dynamic Arrays
 */
#include "iostream"
using namespace std;
class Stack{
    int *arr;
    int nextIndex;
    int size;
public:
    Stack(){
        arr = new int[5];
        nextIndex = 0;
        size = 5;
    }

    void push(int val){
        if(nextIndex==size){
            int *newArr = new int[size*2];
            for(int i =0;i<size;i++){
                newArr[i] = arr[i];
            }
            delete [] arr;
            arr = newArr;
            size*=2;
        }
        arr[nextIndex] = val;
        nextIndex++;
    }
    int pop(){
        if(nextIndex==0){
            cout << "Stack is Empty. " << endl;
            return -1;
        }
        nextIndex--;
        return arr[nextIndex];
    }
    int top(){
        if(nextIndex==0){
            cout << "Stack is Empty. " << endl;
            return -1;
        }
        return arr[nextIndex-1];
    }
    bool isEmpty(){
        return nextIndex==0;
    }
};
int main(){
    Stack s;
    s.push(10);
    s.push(220);
    s.push(10);
    s.push(220);
    s.push(20);
    s.push(120);
    s.push(102);
    s.push(103);
    while(!(s.isEmpty())){
        cout << s.pop() << endl;
    }
    cout << endl;
}