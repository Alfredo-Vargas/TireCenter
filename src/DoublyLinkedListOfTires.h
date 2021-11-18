#pragma once
#include <iostream>
#include "TireNode.h"

class DoublyLinkedListOfTires
{
public:
	// We declare the constructor and destructor respectively:
	~DoublyLinkedListOfTires();

	void addTire(unsigned*);
	void deleteTire(void);
	void displayTires(void);
	void displayStock(void);
	void updateStock(void);
	void filterTiresBySize(void);
	void loadFromFile(void);
	void saveToFile(void);
	TireNode* head;
	TireNode* tail;
};
