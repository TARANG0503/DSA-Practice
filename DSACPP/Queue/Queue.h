#pragma once
/*
Queue class having functionality of Enqueue, Dequeue and some associative features (isEmpty etc.)
*/

template<class T>
class Queue {
public:
	T* queue;
	int size;
	int rear, front;
	int count;

public:
	Queue();
	Queue(const Queue&);
	Queue(int);
	void enQueue(T);
	T deQueue();
	T Front();
	T Rear();
	bool isFull();
	bool isEmpty();
	void showStructure();
	void resize();
	~Queue();
};

