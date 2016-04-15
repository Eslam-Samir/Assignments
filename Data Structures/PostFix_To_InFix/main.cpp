#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

void main()
{
	Stack<string> s;
	string postFx;
	string inFix, first, second, specialOp;
	char previousOperator = ' ';

	cout << "Enter The Postfix: " << endl;
	// use space as a separator (	e.g.	24 5 + 4 * 76 /		===>	(24 + 5) * 4 / 76	)
	getline(cin, postFx);

	for(int i = 0, n = postFx.length(); i < n; i++)
	{
		if(postFx.at(i) == ' ')
			continue;
		if(postFx.at(i) == '*' || postFx.at(i) == '/' || postFx.at(i) == '+' || postFx.at(i) == '-' || postFx.at(i) == '^')
		{
			second = s.pop();
			first = s.pop();
			if((previousOperator == '+' || previousOperator == '-') && (postFx.at(i) == '*' || postFx.at(i) == '/'))
			{
				first = "(" + first + ")";
			}
			else if((previousOperator == '+' || previousOperator == '-') && postFx.at(i) == '-')
			{
				second = "(" + second + ")";
			}
			inFix = first + " " + postFx.at(i) + " " + second;
			s.push(inFix);
			previousOperator = postFx.at(i);
		}
		else if(( specialOp = postFx.substr(i,3)) == "sin" || ( specialOp = postFx.substr(i,3)) == "cos"
			|| ( specialOp = postFx.substr(i,3)) == "tan" || ( specialOp = postFx.substr(i,4)) == "sqrt" )
		{
			second = s.pop();
			second = specialOp+"("+second+")";
			s.push(second);
			i += specialOp.length() - 1;
		}
		else
		{
			s.push(postFx.substr(i,postFx.substr(i, postFx.length()-1).find(" ")));

			i += postFx.substr(i, postFx.length()-1).find(" ");
		}

	}
	inFix = s.pop();
	if(s.isEmpty())
	{
		cout << "The Infix: " << inFix << endl;
	}	
	else
	{
		cout << "Wrong Format";
	}
	system("pause");
}