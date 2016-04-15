#include "sparsePolynomial.h"

sparsePolynomial::sparsePolynomial()
{}

sparsePolynomial::sparsePolynomial(double valueArr[],int orderArr[], int size)
{
	for(int i = size - 1; i >= 0; i--)
	{
		if(valueArr[i] != 0)
			addTerm(valueArr[i], orderArr[i]);
	}
}

double sparsePolynomial::evaluate(double x)
{
	if(isEmpty())
		return 0;

	std::list<node>::iterator it = linkedList.begin();
	std::list<node>::iterator nextIt = linkedList.begin();
	double answer = 0;

	for(; it != linkedList.end(); it++)
	{
		if(it->getOrder() == 0)
			answer = (answer + it->getData());
		else
		{
			double value = x;
			if(++nextIt != linkedList.end())
			{
				int n = it->getOrder() - nextIt->getOrder();
				for(int i = n; i > 1; i--)
				{
					value *= x;
				}
			}
			answer = (answer + it->getData()) * value;
		}
	}
	return answer;
}

void sparsePolynomial::differentiate()
{
	if(isEmpty())
		return;

	std::list<node>::iterator it = linkedList.begin();

	while(it != linkedList.end())
	{
		it->setData(it->getData() * it->getOrder());
		it->setOrder(it->getOrder() - 1);
		it++;
	}
	if(linkedList.back().getOrder() < 0)
		linkedList.pop_back();
}

void sparsePolynomial::print()
{
	if(isEmpty())
		return;

	std::list<node>::iterator it = linkedList.begin();
	std::stringstream ss;

	ss << it->getData(); // convert to string
	std::string poly = ss.str() + " * x^" + std::to_string(it->getOrder());
	it++;
	ss.str(std::string()); // clear string stream

	while(it != linkedList.end())
	{
		if(it->getData() > 0)
		{
			ss << it->getData();
			poly += " + ";
			poly += ss.str();
			if(it->getOrder() != 0)
				poly += " * x^" + std::to_string(it->getOrder());
		}
		else if(it->getData() < 0)
		{
			ss << -1 * it->getData();
			poly += " - ";
			poly += ss.str();
			if(it->getOrder() != 0)
				poly += " * x^" + std::to_string(it->getOrder());
		}
		ss.str(std::string());
		it++;
	}
	std::cout << "Polynomial: " << poly << std::endl;
}

sparsePolynomial sparsePolynomial::multiply(sparsePolynomial poly)
{
	sparsePolynomial result, tmp;
	if(isEmpty() || poly.isEmpty())
		return result;

	std::list<node>::iterator it1 = getList().begin();
	for(it1; it1 != getList().end(); it1++)
	{
		tmp = poly;
		std::list<node>::iterator it2 = tmp.getList().begin();
		for(it2; it2 != tmp.getList().end(); it2++)
		{
			it2->setData(it1->getData() * it2->getData());
			it2->setOrder(it1->getOrder() + it2->getOrder());
		}
		result = result.add(tmp);
	}

	return result;
}

sparsePolynomial sparsePolynomial::add(sparsePolynomial poly)
{
	sparsePolynomial result;

	if(isEmpty())
		return poly;
	else if(poly.isEmpty())
		return *this;
	else if(poly.isEmpty() && isEmpty())
		return result;

	std::list<node>::reverse_iterator it1 = getList().rbegin();
	std::list<node>::reverse_iterator it2 = poly.getList().rbegin();

	while(it1 != linkedList.rend() && it2 != poly.getList().rend())
	{
		if(it1->getOrder() == it2->getOrder())
		{
			result.addTerm((it1->getData() + it2->getData()), it1->getOrder());
			it1++; it2++;
		}
		else if(it1->getOrder() < it2->getOrder())
		{
			result.addTerm(it1->getData(), it1->getOrder());
			it1++;
		}
		else if(it2->getOrder() < it1->getOrder())
		{
			result.addTerm(it2->getData(), it2->getOrder());
			it2++;
		}
	}
	
	while(it1 != linkedList.rend())
	{
		result.addTerm(it1->getData(), it1->getOrder());
		it1++;
	}
	while(it2 != poly.getList().rend())
	{
		result.addTerm(it2->getData(), it2->getOrder());
		it2++;
	}
	return result;
}

bool sparsePolynomial::isEmpty()
{
	if(linkedList.empty())
		return true;
	else
		return false;
}

int sparsePolynomial::getOrder()
{
	if(linkedList.empty())
		return 0;
	else
		return linkedList.front().getOrder();
}

void sparsePolynomial::addTerm(double value, int order)
{
	linkedList.push_front(node(value, order));
}

std::list<node> & sparsePolynomial::getList()
{
	return linkedList;
}