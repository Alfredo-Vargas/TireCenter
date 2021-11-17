#pragma once
#include <iostream>
#include "Date.h"
#include "DoublyLinkedListOfTires.h"
#include "DoublyLinkedListOfRims.h"
#include "DoublyLinkedListOfCustomers.h"

class InvoiceNode
{
private:
	std::string id;
	Date date;
	CustomerNode customer;

	DoublyLinkedListOfTires* listOfTires;
	DoublyLinkedListOfRims* listOfRims;
	DoublyLinkedListOfCustomers* listOfCustomers;

public:
	std::string getID() { return id; }
	void setID(unsigned*);
	void copyID(std::string);		// this is needed when want to retrieve data from a file!

	Date getDate() { return date; }
	void setDate(void);
	void copyDate(Date);

	CustomerNode getCustomer() { return customer; }
	void setCustomer(CustomerNode);

	DoublyLinkedListOfTires cartOfTires;
	DoublyLinkedListOfRims cartOfRims;

	InvoiceNode* Prev;
	InvoiceNode* Next;
};
