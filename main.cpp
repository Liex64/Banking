#include <iostream>
#include "Bank.h"

int main() {
	Bank bank;
	bank.createAccount("Alex", "Obama", 1000, 5000, "helloworld01");
	bank.createAccount("John", "Smith", 1001, 10000, "mypassword02");
	bank.createAccount("Emily", "Jones", 1002, 2500, "letmein12345");
	bank.createAccount("Sarah", "Taylor", 1003, 8000, "123456789012");
	bank.createAccount("Michael", "Brown", 1004, 1500, "secretpass12");
	bank.createAccount("David", "Lee", 1005, 12000, "password1234");
	bank.createAccount("Jessica", "Wang", 1006, 3000, "mysecretpass");
	bank.createAccount("Matthew", "Liu", 1007, 500, "hello12345678");
	bank.createAccount("Sophia", "Chen", 1008, 1000, "mypasswordhere");
	bank.createAccount("Ryan", "Zhang", 1009, 7000, "mypassword7890");
	bank.showMenu();
}