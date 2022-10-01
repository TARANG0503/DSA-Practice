#pragma once
/*
Stack ADT:
Individual items can be added and stored using a push operation
Individual items can be removed and extracted using a push operation
*/

template<class T>
class MyStack {
private:
	int size;
	int top;
	T* stack;
public:
	MyStack();
	MyStack(int);
	void Push(T x);
	T Pop();
	T Peek();
	bool isFull();
	bool isEmpty();
	void resize();
	~MyStack();
};


