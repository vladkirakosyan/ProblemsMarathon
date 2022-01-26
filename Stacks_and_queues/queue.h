#ifndef QUEUE_H
#define QUEUE_H

#include "Stack3h.h"
template <typename T>
class Queue
{
public:
	explicit Queue(int cap = 100);
	Queue(const Queue<T>&);
	~Queue() = default;
	Queue<T>& operator=(Queue<T>& rhs);

public:
	void enqueue1(const T&);
	void enqueue2(const T&);
	T dequeue1();
	T dequeue2();

	bool isFull1() const;
	bool isFull2() const;
	bool isEmpty1() const;
	bool isEmpty2() const;

private:
	Stack<T> _def;
	Stack<T> _tmp;
	int _cap;
};

#include "queue.hpp"
#endif // QUEUE_H
