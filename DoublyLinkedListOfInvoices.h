#pragma once
#include <iostream>
#include "InvoiceNode.h"

class DoublyLinkedListOfInvoices
{
public:
	~DoublyLinkedListOfInvoices();

	void placeOrder(unsigned*, DoublyLinkedListOfTires*, DoublyLinkedListOfRims*, DoublyLinkedListOfCustomers*);   // we add an invoice
	void displayInvoices(void);
	void loadFromFile(void);
	void saveToFile(void);
	InvoiceNode* head;
	InvoiceNode* tail;
};

