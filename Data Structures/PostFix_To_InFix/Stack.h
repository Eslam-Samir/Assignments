#ifndef __STACK__
#define __STACK__

#include "LinkedList.h"

template <class T> class Stack
{
private:
	LinkedList<T> list;
public:
	Stack()
	{
		
	}
	bool isEmpty()
	{
		return list.isEmpty();
	}
	void push(T item)
	{
		list.addFront(item);
	}
	T pop()
	{
		T item = list.getFront();
		list.removeFront();
		return item;
	}

};

#endif // __STACK__