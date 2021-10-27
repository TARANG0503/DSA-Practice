#include <iostream>
#include <cstdlib>
using namespace std;
 
// Define the default capacity of the stack
#define SIZE 10
 
// A class to represent a stack
class stack
{
    int *arr;
    int top;
    int capacity;
 
public:
    stack(int size = SIZE);         // constructor
    ~stack();                       // destructor
 
    void push(int);
    int pop();
    int peek();
 
    int size();
    bool isEmpty();
    bool isFull();
};
 
// Constructor to initialize the stack
stack::stack(int size)
{
    arr = new int[size];
    capacity = size;
    top = -1;
}
 
// Destructor to free memory allocated to the stack
stack::~stack() {
    delete[] arr;
}
 
// Utility function to add an element `x` to the stack
void stack::push(int x)
{
    if (isFull())
    {
        cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
 
    cout << "Inserting " << x << endl;
    arr[++top] = x;
}
 
// Utility function to pop a top element from the stack
int stack::pop()
{
    // check for stack underflow
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
 
    cout << "Removing " << peek() << endl;
 
    // decrease stack size by 1 and (optionally) return the popped element
    return arr[top--];
}
 
// Utility function to return the top element of the stack
int stack::peek()
{
    if (!isEmpty()) {
        return arr[top];
    }
    else {
        exit(EXIT_FAILURE);
    }
}
 
// Utility function to return the size of the stack
int stack::size() {
    return top + 1;
}
 
// Utility function to check if the stack is empty or not
bool stack::isEmpty() {
    return top == -1;               // or return size() == 0;
}
 
// Utility function to check if the stack is full or not
bool stack::isFull() {
    return top == capacity - 1;     // or return size() == capacity;
}
 
int main()
{
    stack pt(3);
 
    pt.push(1);
    pt.push(2);
 
    pt.pop();
    pt.pop();
 
    pt.push(3);
 
    cout << "The top element is " << pt.peek() << endl;
    cout << "The stack size is " << pt.size() << endl;
 
    pt.pop();
 
    if (pt.isEmpty()) {
        cout << "The stack is empty\n";
    }
    else {
        cout << "The stack is not empty\n";
    }
 
    return 0;
}
