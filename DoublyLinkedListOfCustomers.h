#pragma once
#include <iostream>
#include "CustomerNode.h"

class DoublyLinkedListOfCustomers
{
public:
	// We declare the constructor and destructor respectively:
	~DoublyLinkedListOfCustomers();

	void addCustomer(unsigned*);
	void deleteCustomer(void);
	void displayCustomers(void);
	void loadFromFile(void);
	void saveToFile(void);

	CustomerNode* head;
	CustomerNode* tail;
};
