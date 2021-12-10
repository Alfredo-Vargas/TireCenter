#pragma once
#include <iostream>
#include "CustomerNode.h"

class DoublyLinkedListOfCustomers
{
public:
	void addCustomer(unsigned*);
	void deleteCustomer(void);
	void displayCustomers(void);
	void loadFromFile(void);
	void saveToFile(void);

	CustomerNode* head;
	CustomerNode* tail;
};
