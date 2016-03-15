#include <iostream>
#include "BankAccount.h"
using namespace std;

void main()
{
	string name, number;
	double balance;
	double money = 0;
	int choice = 0;
	cout << "Please Enter Depositor's Name: ";
	getline(cin, name);
	cout << "Please Enter Account Number: ";
	getline(cin, number);
	cout << "Please Enter Balance: ";
	cin >> balance;
	// Create a bank account
	BankAccount account(name, number, balance);

	// Display account information
	cout << "\nDepositor Name: " << account.getDepositorName()<<endl;
	cout << "Account Number: " << account.getAccountNumber()<<endl;
	cout << "Balance: " << account.getBalance()<<endl;

	while(choice != 3)
	{
		cout << "\n1- Deposite\n2- Withdraw\n3- Quit\nEnter 1, 2, or 3" << endl;
		cin >> choice;
		if (choice == 1)
		{
			// deposite amount of money
			cout << "Enter the ammount to deposite: ";
			cin >> money;
			account.deposite(money);
			cout << "\nAfter Deposite: Balance = " << account.getBalance() << endl;
		}
		else if (choice == 2)
		{
			// withdraw amount of money
			cout << "Enter the ammount to withdraw: ";
			cin >> money;
			if(account.withdraw(money))
			{
				cout << "After withdraw: Balance = " << account.getBalance() << endl;
			}
			else
			{
				cout<<"You can't withdraw this amount"<<endl;
			}
		}
		else if (choice != 3)
		{
			cout << "Please Enter 1, 2, or 3" <<endl;
		}
	}
}
