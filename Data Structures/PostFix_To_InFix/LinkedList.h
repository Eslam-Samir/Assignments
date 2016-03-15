#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>
#include "Node.h"

template <class T> class LinkedList
{
private:
	Node<T>* head;
	int size;
	void printRecursive(Node<T>* n)
	{
		if(n != nullptr)
		{
			std::cout << n->getData();
			if(n->getNext() != nullptr)
				std::cout << ", ";
			printRecursive(n->getNext());
		}
	}
public:
	LinkedList()
	{
		head = nullptr;
		size = 0;
	}
	LinkedList(T d)
	{
		head = new Node<T>(d);
		size = 1;
	}
	~LinkedList()
	{
		clear();
	}
	bool isEmpty()
	{
		if(head == nullptr)
			return true;
		else
			return false;
	}
	int getSize()
	{
		return size;
	}
	T getFront()
	{
		return head->getData();
	}
	void addFront(T d)
	{
		if(isEmpty())
		{
			head = new Node<T>(d);
		}
		else
		{
			Node<T>* tmp = new Node<T>(d);
			tmp->setNext(head);
			head = tmp;
		}
		size++;
	}
	void addEnd(T d)
	{
		if(isEmpty())
		{
			head = new Node<T>(d);
		}
		else
		{
			Node<T>* tmp = head;
			Node<T>* end = new Node<T>(d);
			while(tmp->getNext() != nullptr)
				tmp = tmp->getNext();
			tmp->setNext(end);
		}
		size++;
	}
	void insert(T d, int index)
	{
		if(index == 0)
		{
			addFront(d);
		}
		else if(index == getSize())
		{
			addEnd(d);
		}
		else if(index > 0 && index < getSize())
		{
			Node<T>* tmp = head;
			Node<T>* newNode = new Node<T>(d);
			for(int i = 0; i < index-1; i++)
				tmp = tmp->getNext();
			newNode->setNext(tmp->getNext());
			tmp->setNext(newNode);
			size++;
		}
	}
	void removeFront()
	{
		if(!isEmpty())
		{
			Node<T>* tmp = head;
			head = tmp->getNext();
			delete tmp;
			size--;
		}
	}
	void removeEnd()
	{
		if(isEmpty())
		{
			return;
		}
		else if(getSize() == 1)
		{
			removeFront();
		}
		else
		{
			Node<T>* prev = head;
			Node<T>* tmp = prev->getNext();
			while(tmp->getNext() != nullptr)
			{
				prev = prev->getNext();
				tmp = tmp->getNext();
			}
			prev->setNext(nullptr);
			delete tmp;
			size--;
		}
	}
	void remove(int index)
	{
		if(index == 0)
		{
			removeFront();
		}
		else if(index == getSize() - 1)
		{
			removeEnd();
		}
		else if(index > 0 && index < getSize() - 1)
		{
			Node<T>* prev = head;
			Node<T>* tmp = prev->getNext();
			for(int i = 0; i < index-1; i++)
			{
				prev = prev->getNext();
				tmp = tmp->getNext();
			}
			prev->setNext(tmp->getNext());
			delete tmp;
			size--;
		}
	}
	int find(T d)
	{
		if(!isEmpty())
		{
			Node<T>* tmp = head;
			int index;
			for(index = 0; tmp != nullptr; index++)
			{
				if(tmp->getData() == d)
					return index;
				tmp = tmp->getNext();
			}
		}
		return -1;
	}
	void printList()
	{
		std::cout << "(";
		printRecursive(head);
		std::cout << ")" << endl;
	}
	void clear()
	{
		while(!isEmpty())
		{
			removeFront();
		}
	}
};

#endif // __LINKEDLIST__