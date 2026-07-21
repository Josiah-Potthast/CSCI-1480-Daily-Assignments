#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include "BankAccount.h"
#include <iostream>
using namespace std;

class CheckingAccount : public BankAccount
{
public:
	CheckingAccount();
	CheckingAccount(double balance, double annualInterestRate);

	void transfer(double amount, BankAccount& to) override;
	void withdraw(double amount) override;
	void monthlyProc() override;
};

#endif