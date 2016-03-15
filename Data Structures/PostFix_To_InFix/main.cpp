#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

void main()
{
	Stack<string> s;
	string postFx;
	string inFix, first, second;
	char previousOperator = ' ';

	// use space as a separator (e.g.   24 5 + 4 * 76 /   ===>   (24 + 5) * 4 / 76)
	getline(cin, postFx);

	for(int i = 0, n = postFx.length(); i < n; i++)
	{
		if(postFx.at(i) == ' ')
			continue;
		if(postFx.at(i) == '*' || postFx.at(i) == '/' || postFx.at(i) == '+' || postFx.at(i) == '-')
		{
			second = s.pop();
			first = s.pop();
			if((previousOperator == '+' || previousOperator == '-') && (postFx.at(i) == '*' || postFx.at(i) == '/'))
			{
				first = "(" + first + ")";
			}
			inFix = first + " " + postFx.at(i) + " " + second;
			s.push(inFix);
			previousOperator = postFx.at(i);
		}
		else
		{
			s.push(postFx.substr(i,postFx.substr(i, postFx.length()-1).find(" ")));

			i += postFx.substr(i, postFx.length()-1).find(" ");
		}

	}
	while(!s.isEmpty())
		cout << s.pop() << endl;
		
	system("pause");
}