#include "BankAccount.h"

// class function members
BankAccount::BankAccount(std::string name, std::string number, double b)
{
	depositorName = name;
	accountNumber = number;
	balance = b;
}
const std::string & BankAccount::getDepositorName()
{
	return 	depositorName;
}
const std::string & BankAccount::getAccountNumber()
{
	return 	accountNumber;
}
double BankAccount::getBalance()
{
	return balance;
}
void BankAccount::deposite(double amount)
{
	balance += amount;
}
// return false on error
bool BankAccount::withdraw(double amount)
{
	if (amount <= balance)
	{
		balance -= amount;
		return true;
	}
	else
	{
		return false;
	}
}