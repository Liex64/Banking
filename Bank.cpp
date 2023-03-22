#include "Bank.h"
//#include <fstream>
#include <iostream>

Bank::Bank() {
	std::vector<Account> accountPool = std::vector<Account>();
};

void Bank::accountScreen(Account& acc) {
	do {
		acc.summary();
		std::cout << "Menu" << std::endl;
		std::cout << "1. Deposit" << std::endl;
		std::cout << "2. Withdraw" << std::endl;
		std::cout << "3. Transfer Funds" << std::endl;
		std::cout << "4. Exit" << std::endl;

		int choice;
		std::cin >> choice;

		switch (choice) {
		case 1:
			depositScreen(acc);
			continue;
		case 2:
			withdrawScreen(acc);
			continue;
		case 3:
			transferScreen(acc);
			continue;
		case 4:
			return;
		default:
			std::cout << "Wrong choice. Try again." << std::endl;
			continue;
		}
	} while (true);
}

void Bank::depositScreen(Account& acc) {
	std::cout << "Amount to deposit: ";
	int amount;
	std::cin >> amount;
	acc.deposit(amount);
}

void Bank::withdrawScreen(Account& acc) {
	std::cout << "Your balance: " << acc.getValue() << std::endl;
	std::cout << "Amount to withdraw: ";
	int amount;
	std::cin >> amount;
	acc.withdraw(amount);
}

void Bank::transferScreen(Account& acc) {
	int recipientID;
	int amount;
	std::cout << "Your balance: " << acc.getValue() << std::endl;
	std::cout << "Recipient ID: ";
	std::cin >> recipientID;
	std::cout << "Amount: ";
	std::cin >> amount;
	Account& recipient = *findAccount(recipientID);
	acc.withdraw(amount);
	recipient.deposit(amount);
	std::cout << acc.getAccountID() << " to " << recipient.getAccountID() << " - " << amount << std::endl;
}

void Bank::registerScreen() {
	std::string firstName;
	std::string lastName;
	std::cout << "First Name: ";
	std::cin >> firstName;
	std::cout << "\nLast Name: ";
	std::cin >> lastName;
	std::cout << "\nYour credentials" << std::endl;
	std::pair<int, std::string> credentials = createAccount(firstName, lastName);
	std::cout << "Account ID: " << credentials.first << std::endl;
	std::cout << "Password: " << credentials.second << std::endl;
}

void Bank::loginScreen() {
	while (true) {
		int accountID;
		std::string password;
		std::cout << "Account ID: ";
		std::cin >> accountID;
		std::cout << "Password: ";
		std::cin >> password;
		std::vector<Account>* pool = &currentPool;
		Account* acc = findAccount(accountID);
		if (acc == nullptr) {
			std::cout << "Account ID or password is wrong." << std::endl;
			continue;
		}
		accountScreen(*acc);
	}
}

Account* Bank::findAccount(int id) {
	std::vector<Account>& pool = currentPool;

	for (auto it = pool.begin(); it != pool.end(); ++it) {
		if (it->getAccountID() == id) {
			return &(*it);
		}
	}
	return nullptr;
}
void Bank::showMenu()
{
	while (true) {
		std::cout << "Banking System Menu:" << std::endl;
		std::cout << "1. Register" << std::endl;
		std::cout << "2. Login" << std::endl;
		std::cout << "3. Exit" << std::endl;

		int choice;
		std::cin >> choice;
		switch (choice) {
		case 1:
			registerScreen();
			break;
		case 2:
			loginScreen();
		case 3:
			//makeSave();
			return;
		default:
			continue;
		}
	}
}

std::pair<int, std::string> Bank::createAccount(std::string first, std::string last) {
	std::vector<Account>* pool = &currentPool;
	Account acc = Account(first, last);
	pool->push_back(acc);
	std::pair<int, std::string> arr = std::make_pair(acc.getAccountID(), acc.getPassword());
	return arr;

}

void Bank::createAccount(std::string first, std::string last, int id, int val, std::string pass) {
	std::vector<Account>* pool = &currentPool;
	Account acc = Account(first, last, id, val, pass);
	pool->push_back(acc);

}

void Bank::makeSave() {
}