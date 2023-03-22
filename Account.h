#pragma once
#include <string>

class Account {
public:
	Account(std::string firstName, std::string lastName);
	Account(std::string firstName, std::string lastName, int id, int val, std::string pass);

	std::string getFirstName();
	std::string getLastName();
	std::string getPassword();
	bool checkPassword(std::string);
	int getAccountID();
	int getValue();
	void setValue(int);
	void summary();
	void deposit(int);
	void withdraw(int);
private:
	std::string firstName;
	std::string lastName;
	int accountID;
	int value;
	static int nextAccountID;
	std::string password;
	std::vector<std::string> operationHistory;
};