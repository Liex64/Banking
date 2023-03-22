#include "Account.h"
#include <ctime>
#include <random>
#include <iostream>

int Account::nextAccountID = 100;

std::string generatePass() {
	const std::string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
	const int passwordLength = 12;
	std::string password;
	std::srand(std::time(nullptr));

	for (int i = 0; i < passwordLength; i++) {
		password += chars[std::rand() % chars.length()];
	}
	return password;
}

Account::Account(std::string first, std::string last) : firstName(first), lastName(last){
	value = 0;
	accountID = nextAccountID;
	nextAccountID++;
	password = generatePass();
};

Account::Account(std::string first, std::string last, int id, int val, std::string pass) : 
	firstName(first), lastName(last), accountID(id), value(val), password(pass) {
	
}

std::string Account::getFirstName() {
	return firstName;
}

std::string Account::getLastName() {
	return lastName;
}

int Account::getAccountID() {
	return accountID;
}

int Account::getValue() {
	return value;
}

std::string Account::getPassword() {
	return password;
}

bool Account::checkPassword(std::string passIn) {
	if (passIn == password) {
		return true;
	}
	return false;
}

void Account::setValue(int inValue) {
	value = inValue;
}

void Account::summary() {
	std::cout << "First Name: " << getFirstName() << std::endl;
	std::cout << "Last Name: " << getLastName() << std::endl;
	std::cout << "Account ID: " << getAccountID() << std::endl;
	std::cout << "Account Balance: " << getValue() << std::endl;
}

void Account::deposit(int amount) {
	value += amount;
}

void Account::withdraw(int amount) {
	if (value >= amount) {
		value -= amount;
	}
	else {
		std::cout << "Not enough funds." << std::endl;
	}
}
