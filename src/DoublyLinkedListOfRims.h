#pragma once
#include <iostream>
#include "RimNode.h"

class DoublyLinkedListOfRims
{
public:
	// We declare the constructor and destructor respectively:
	~DoublyLinkedListOfRims();

	void addRim(unsigned*);
	void deleteRim(void);
	void displayRims(void);
	void displayStock(void);
	void updateStock(void);
	void filterRimsBySize(void);
	void loadFromFile(void);
	void saveToFile(void);
	RimNode* head;
	RimNode* tail;
};

