#pragma once
#include <iostream>
#include "DoublyLinkedListOfTires.h"
#include "DoublyLinkedListOfRims.h"
#include "DoublyLinkedListOfArticles.h"
#include "DoublyLinkedListOfCustomers.h"
#include "DoublyLinkedListOfInvoices.h"

class TireCenter
{
private:
	std::string name;
	std::string address;
public:

	std::string getName() { return name; }
	void setName(std::string);

	std::string getAddress() { return address; }
	void setAddress(std::string);

	void welcomeMessage(void);
	unsigned logIn (void);
	unsigned mainMenu(void);
	unsigned customerMenu(unsigned);
	unsigned articleMenu(unsigned);
	unsigned stockMenu(void);

    DoublyLinkedListOfArticles listOfArticles;
	DoublyLinkedListOfTires listOfTires;
	DoublyLinkedListOfRims listOfRims;
	DoublyLinkedListOfCustomers listOfCustomers;
	DoublyLinkedListOfInvoices listOfInvoices;
};