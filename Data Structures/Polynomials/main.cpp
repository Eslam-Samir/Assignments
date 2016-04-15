#include <iostream>
#include <string>
#include "polynomial.h"
#include "sparsePolynomial.h"
using namespace std;
template <class T>
int fillArray(string coeff, T arr[], int order)
{
	if(coeff.empty())
		return 0;

	stack<string> s;
	string value;
	string delimiter = " ";
	size_t pos = 0;
	int k = 0;
	for(int i = 0; i < coeff.length(); i++)
	{
		if(coeff.at(i) == ' ')
			continue;
		else
		{
			if((pos = coeff.substr(i, coeff.length()-1).find(delimiter)) != std::string::npos)
			{
				value = coeff.substr(i, pos);
				if(k > order)
				{
					return 0;
				}
				arr[k] = stof(value);
				k++;
				i += pos;
			}
			else
			{
				value = coeff.substr(i, coeff.length());
				arr[k] = stod(value);
				break;
			}
		}
	}

	return k+1;
}

int main()
{
	int type, operation;
	cout << "Choose Polynomial Type 1.Normal 2.Sparse: ";
	cin >> type;
	cout << "Choose an Operation 1.evaluate 2.multiply 3.differentiate: ";
	cin >> operation;
	int order, size;
	string input;
	cout << "Enter The Polynomial Order: ";
	cin >> order;
	double * coeff = new double[order+1];
	cout << "Enter The Coefficients: " << endl;
	getline(cin, input); // skip previous \n
	getline(cin, input);
	size = fillArray(input, coeff, order+1);

	switch(type)
	{
	case 1:
		if(operation == 1)
		{
			int x;
			polynomial poly(coeff, size);
			poly.print();
			cout << "Enter Value of x: " << endl;
			cin >> x;

			cout << "P(" << x << ") = " << poly.evaluate(x) << endl;
		}
		else if(operation == 2)
		{
			polynomial poly1(coeff, size);
			poly1.print();
			int order2, size2;
			string input2;
			cout << "Enter The Polynomial Order: ";
			cin >> order2;
			double * coeff2 = new double[order2+1];
			cout << "Enter The Coefficients: " << endl;
			getline(cin, input2); // skip previous \n
			getline(cin, input2);
			size2 = fillArray(input2, coeff2, order2+1);
			polynomial poly2(coeff2, size2);
			poly2.print();

			polynomial result = poly1.multiply(poly2);
			cout << "Result: ";
			result.print();
			delete [] coeff2;
		}
		else if(operation == 3)
		{
			polynomial poly(coeff, size);
			poly.print();
			poly.differentiate();
			cout << "Result: ";
			poly.print();
		}
		break;
	case 2:
		if(operation == 1)
		{
			int x;
			int * orders = new int[order+1];
			cout << "Enter The Orders: " << endl;
			getline(cin, input);
			fillArray(input, orders, order+1);

			sparsePolynomial poly(coeff, orders, size);
			poly.print();
			cout << "Enter Value of x: " << endl;
			cin >> x;

			cout << "P(" << x << ") = " << poly.evaluate(x) << endl;
			delete [] orders;
		}
		else if(operation == 2)
		{
			int * orders1 = new int[order+1];
			int * orders2 = new int[order+1];
			cout << "Enter The Orders: " << endl;
			getline(cin, input);
			fillArray(input, orders1, order+1);
			sparsePolynomial poly1(coeff, orders1, size);
			poly1.print();

			int order2, size2;
			string input2;
			cout << "Enter The Polynomial Order: ";
			cin >> order2;
			double * coeff2 = new double[order2+1];
			cout << "Enter The Coefficients: " << endl;
			getline(cin, input2); // skip previous \n
			getline(cin, input2);
			size2 = fillArray(input2, coeff2, order2+1);
			cout << "Enter The Orders: " << endl;
			getline(cin, input2);
			fillArray(input2, orders2, order2+1);

			sparsePolynomial poly2(coeff2, orders2, size2);
			poly2.print();

			sparsePolynomial result = poly1.multiply(poly2);
			cout << "Result: ";
			result.print();
			delete [] orders1;
			delete [] orders2;
			delete [] coeff2;
		}
		else if(operation == 3)
		{
			int * orders = new int[order+1];
			cout << "Enter The Orders: " << endl;
			getline(cin, input);
			fillArray(input, orders, order+1);

			sparsePolynomial poly(coeff, orders, size);
			poly.print();
			poly.differentiate();
			cout << "Result: ";
			poly.print();
			delete [] orders;
		}
		break;
	}
	delete [] coeff;
	system("pause");
	return 0;
}
