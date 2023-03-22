#pragma once
#include "Account.h"
#include <vector>
#include <utility>


class Bank
{
public:
	Bank();
	void showMenu();
	std::pair<int, std::string> createAccount(std::string, std::string);
	void createAccount(std::string, std::string, int, int, std::string);
	void loginScreen();
	void registerScreen();
	void accountScreen(Account&);
	void depositScreen(Account&);
	void withdrawScreen(Account&);
	void transferScreen(Account&);
	void makeSave();
	Account* findAccount(int);
private:
	std::vector<Account> currentPool;
};

