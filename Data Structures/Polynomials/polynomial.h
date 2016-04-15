#ifndef __POLYNOMIAL__
#define __POLYNOMIAL__

#include <list>
#include <iterator>
#include <string>
#include <stack>
#include <iostream>
#include <sstream>

class polynomial
{
private:
	std::list<double> linkedList;

public:
	polynomial();
	polynomial(double arr[], int size);
	double evaluate(double x);
	void differentiate();
	void print();

	polynomial multiply(polynomial poly);
	polynomial add(polynomial poly);

	bool isEmpty();
	int getOrder();
	void addTerm(double value);
	std::list<double> & getList();
};

#endif // __POLYNOMIAL__