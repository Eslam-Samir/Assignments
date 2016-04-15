#ifndef __SPARSEPOLYNOMIAL__
#define __SPARSEPOLYNOMIAL__

#include <list>
#include <iterator>
#include <string>
#include <stack>
#include <iostream>
#include <sstream>

class node
{
private:
	double data;
	int order;

public:
	node(double data, int order)
	{
		this->data = data;
		this->order = order;
	}
	void setData(double data) 
	{
		this->data = data;
	}
	void setOrder(int order)
	{
		if(order >= 0)
			this->order = order;
	}
	double getData()
	{
		return data;
	}
	int getOrder()
	{
		return order;
	}
};

class sparsePolynomial
{
private:
	std::list<node> linkedList;

public:
	sparsePolynomial();
	sparsePolynomial(double valueArr[],int orderArr[], int size);
	double evaluate(double x);
	void differentiate();
	void print();

	sparsePolynomial multiply(sparsePolynomial poly);
	sparsePolynomial add(sparsePolynomial poly);

	bool isEmpty();
	int getOrder();
	void addTerm(double value, int order);
	std::list<node> & getList();
};

#endif // __SPARSEPOLYNOMIAL__