#ifndef __BankAccount__
#define __BankAccount__

#include <string>

class BankAccount
{
	private:
		std::string depositorName;
		std::string accountNumber;
		double balance;
	public:
		BankAccount(std::string name, std::string number, double balance = 1000);
		const std::string & getDepositorName();
		const std::string & getAccountNumber();
		double getBalance();
		void deposite(double amount);
		bool withdraw(double amount);
};

#endif