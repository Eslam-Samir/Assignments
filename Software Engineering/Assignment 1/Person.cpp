#include <iostream>
#include <string>

using namespace std;

class Person {
	private:
		static const int LIMIT = 25;
		string lname; // Person’s last name
		char fname[LIMIT]; // Person’s first name
	public:
		// #1
		Person() 
		{ 
			lname = "";
			fname[0] = '\0'; 
		}
		// #2
		Person(const string & ln, const char * fn = "Heyyou")
		{
			int n = strlen(fn);
			if(n >= LIMIT) // check for char array size
			{
				n = LIMIT - 1;
			}
			for(int i = 0; i < n; i++)
			{
				fname[i] = fn[i];
			}
			fname[n] = '\0'; // null terminal

			lname = ln;
		}

		// the following methods display lname and fname
		void Show() 
		{
			cout<<fname<<" "<<lname<<endl;// firstname lastname format
		} 
		void FormalShow()
		{
			cout<<lname<<", "<<fname<<endl;// lastname, firstname format
		}
};

void main()
{
	Person one; // use default constructor
	Person two("Smythecraft"); // use #2 with one default argument
	Person three("Dimwiddy", "Sam"); // use #2, no defaults
	one.Show();
	one.FormalShow();
	cout<<endl;
	two.Show();
	two.FormalShow();
	cout<<endl;
	three.Show();
	three.FormalShow();
	cout<<endl;
	system("pause");
}