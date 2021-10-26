/*
 * Stack implementation using Templates
 */
#include "iostream"
using namespace std;

template <typename T>
class Stack{
    T * arr;
    int nextIndex;
    int size;
public:
    Stack(){
        arr = new T[5];
        nextIndex = 0;
        size  = 5;
    }
    void push(T val){
        if(nextIndex == size){
            T * newArr = new T[size*2];
            for(int i=0;i<size;i++){
                newArr[i] = arr[i];
            }
            delete [] arr;
            arr = newArr;
            size*=2;
        }
        arr[nextIndex] = val;
        nextIndex++;
    }

    T pop(){
        if(nextIndex==0){
            cout << "Stack is Empty";
            return arr[0];
        }
        nextIndex--;
        return arr[nextIndex];
    }
    bool isEmpty(){
        return nextIndex==0;
    }

    T top(){
        if(isEmpty()){
            cout << "Stack is empty ";
            return arr[0];
        }
        return arr[nextIndex-1];
    }
};
int main(){
    Stack<int> s;
    s.push(1);
    s.push(10);
    s.push(220);
    s.push(20);
    s.push(120);
    s.push(102);
    s.push(103);
    Stack<char> s2;
    s2.push('a');
    s2.push('b');
    s2.push('c');
    s2.push('d');
    s2.push('e');
    s2.push('f');
    while (!(s.isEmpty())){
        cout << s.pop() <<" ";
    }
    cout << endl;
    while (!(s2.isEmpty())){
        cout << s2.pop() <<" ";
    }
    cout <<endl;
}