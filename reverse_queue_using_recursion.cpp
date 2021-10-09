#include <bits/stdc++.h>
using namespace std;

void printQueue(queue<long long int> Queue)
{
	while (!Queue.empty()) {
		cout << Queue.front() << " ";
		Queue.pop();
	}
}

void reverseQueue(queue<long long int>& q)
{
	if (q.empty())
		return;

	long long int data = q.front();
	q.pop();

	reverseQueue(q);

	q.push(data);
}

int main()
{
	queue<long long int> Queue;
	Queue.push(56);
	Queue.push(27);
	Queue.push(30);
	Queue.push(45);
	Queue.push(85);
	Queue.push(92);
	Queue.push(58);
	Queue.push(80);
	Queue.push(90);
	Queue.push(100);
	reverseQueue(Queue);
	printQueue(Queue);
}
