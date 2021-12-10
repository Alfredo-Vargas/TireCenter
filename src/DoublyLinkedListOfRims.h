#pragma once
#include <iostream>
#include "RimNode.h"

class DoublyLinkedListOfRims
{
public:
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
