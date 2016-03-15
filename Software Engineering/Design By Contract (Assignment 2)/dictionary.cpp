#include <iostream>
#include <string>
#include "dbc.h"

using namespace std;

class Dictionary 
{
private:
	string names[100];
	string emails[100];
	int size;
	// return true if the key exists in the dictionary and false otherwise
	bool searchkey(string name)
	{
		for(int i = 0; i < size; i++) 
			if(!name.compare(names[i])) 
				return true;
		return false;
	}
public:
	Dictionary()
	{
		size = 0;
	}
	void Add(string name,string email)
	{
        INVARIANT0(size >= 0 && size < 99);
		REQUIRE0(name.compare("") != 0);
		REQUIRE0(email.compare("") != 0);
		REQUIRE0(!searchkey(name));

		names[size] = name;
		emails[size] = email;
		size++;

		ENSURE0(searchkey(name));
		ENSURE0(name.compare(names[size - 1]) == 0);
		ENSURE0(email.compare(emails[size - 1]) == 0);
        INVARIANT0(size > 0 && size <= 99);
	}

	void Remove(string name)
	{
        INVARIANT0(size > 0 && size <= 99);
		REQUIRE0(searchkey(name));
		// a simple example on removing array of numbers
		// if the array is  {1,5,3,4,2,6,7,8,9,10}
		// and its size is 10 elements
		// and i want to remove entry "2"
		// i'll find its index first through the following code segment
		int indextoberemoved;

		for(int i =0;i<size;i++)
		{
			if(names[i] == name)
			{
				indextoberemoved = i;
				break;
			}
		}
		// then i'll move all elements after that index backword one step
		// and with decrementing the size, this is equivalent to removing that element
		size--;
		for(int i = indextoberemoved;i<size;i++)
		{
			names[i] = names[i+1];
			emails[i] = emails[i+1];
		}
		ENSURE0(!searchkey(name));
        INVARIANT0(size >= 0 && size < 99);
	}
	void printentries()
	{
		for(int i =0;i<size;i++)
		{
			cout<<"Entry #"<<i+1<<":"<<endl<<names[i]<<": "<<emails[i]<<endl;
		}
	}
};



void main()
{
	try
	{
	Dictionary x;
	x.Add("omar","omar@live.com");
	x.Add("hassan","hassan@live.com");
	cout<<"Before Deleting Hassan"<<endl;
	x.printentries();
	x.Remove("hassan");
	cout<<"After Deleting Hassan"<<endl;
	x.printentries();
	}
	catch(DesignByContractException e)
	{
		cout<<(string) e;
	}
}
