#include "polynomial.h"

polynomial::polynomial()
{}

polynomial::polynomial(double arr[], int size)
{
	for(int i = size - 1; i >= 0; i--)
	{
		addTerm(arr[i]);
	}
}

double polynomial::evaluate(double x)
{
	if(isEmpty())
		return 0;

	std::list<double>::iterator it;
	double answer = 0;

	for(it = linkedList.begin(); it != linkedList.end(); it++)
	{
		if(*it == linkedList.back())
			answer = (answer + *it);
		else
			answer = (answer + *it) * x;
	}
	return answer;
}

void polynomial::differentiate()
{
	if(isEmpty())
		return;

	std::list<double>::iterator it = linkedList.begin();
	int order = getOrder();

	while(it != linkedList.end())
	{
		*it *= order;
		order--;
		it++;
	}

	linkedList.pop_back();
}

void polynomial::print()
{
	if(isEmpty())
		return;

	std::list<double>::iterator it = linkedList.begin();
	int order = getOrder();
	std::stringstream ss;

	ss << *it++; // convert to string

	std::string poly = ss.str() + " * x^" + std::to_string(order--);
	ss.str(std::string()); // clear string stream

	while(it != linkedList.end())
	{
		if(*it > 0)
		{
			ss << *it;
			poly += " + ";
			poly += ss.str();
			if(order != 0)
				poly += " * x^" + std::to_string(order);
		}
		else if(*it < 0)
		{
			ss << -1 * *it;
			poly += " - ";
			poly += ss.str();
			if(order != 0)
				poly += " * x^" + std::to_string(order);
		}
		ss.str(std::string());
		it++;
		order--;
	}
	std::cout << "P(x) = " << poly << std::endl;
}

polynomial polynomial::multiply(polynomial poly)
{
	polynomial result, tmp;
	if(isEmpty() || poly.isEmpty())
		return result;

	std::list<double>::iterator it1 = getList().begin();
	int order = getOrder();
	for(it1; it1 != getList().end(); it1++)
	{
		tmp = poly;
		std::list<double>::iterator it2 = tmp.getList().begin();
		for(it2; it2 != tmp.getList().end(); it2++)
		{
			*it2 *= *it1;
		}
		for(int i = 0; i < order; i++)
			tmp.getList().push_back(0);
		result = result.add(tmp);
		order--;
	}

	return result;
}

polynomial polynomial::add(polynomial poly)
{
	polynomial result;

	if(isEmpty())
		return poly;
	else if(poly.isEmpty())
		return *this;
	else if(poly.isEmpty() && isEmpty())
		return result;

	std::list<double>::reverse_iterator it1 = getList().rbegin();
	std::list<double>::reverse_iterator it2 = poly.getList().rbegin();

	if(getOrder() < poly.getOrder())
	{
		for(it2; it2 != poly.getList().rend(); it2++)
		{
			if(it1 == getList().rend())
				result.addTerm(*it2);
			else
			{
				result.addTerm(*it1 + *it2);
				it1++;
			}
		}
	}
	else
	{
		for(it1; it1 != getList().rend(); it1++)
		{
			if(it2 == poly.getList().rend())
				result.addTerm(*it1);
			else
			{
				result.addTerm(*it1 + *it2);
				it2++;
			}
		}
	}
	return result;
}

bool polynomial::isEmpty()
{
	if(linkedList.empty())
		return true;
	else
		return false;
}

int polynomial::getOrder()
{
	if(linkedList.empty())
		return 0;
	else
		return linkedList.size() - 1;
}

void polynomial::addTerm(double value)
{
	linkedList.push_front(value);
}

std::list<double> & polynomial::getList()
{
	return linkedList;
}