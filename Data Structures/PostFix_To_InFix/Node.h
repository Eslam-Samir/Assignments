#ifndef __NODE__
#define __NODE__

template <class T> class Node
{
private:
	T data;
	Node* next;
public:
	Node()
	{
		next = nullptr;
		data = 0;
	}
	Node(T d)
	{
		next = nullptr;
		data = d;
	}
	void setNext(Node* n)
	{
		next = n;
	}
	void setData(T d)
	{
		data = d;
	}
	Node* getNext()
	{
		return next;
	}
	T getData()
	{
		return data;
	}
};

#endif // __NODE__