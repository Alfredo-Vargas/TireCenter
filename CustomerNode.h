#pragma once
#include <iostream>

class CustomerNode
{
private:
	std::string id;
	std::string firstname;
	std::string lastname;
	std::string address;
	unsigned type;	// 0 for private 1 for corporate
public:
	std::string getID() { return id; }
	void setID(unsigned*);
	void copyID(std::string);		// this is needed when want to retrieve data from a file!

	std::string getFirstName() { return firstname; }
	void setFirstName(std::string);

	std::string getLastName() { return lastname; }
	void setLastName(std::string);

	std::string getAddress() { return address; }
	void setAddress(std::string);

	unsigned getType() { return type; }
	void setType(unsigned);

	CustomerNode* Prev;
	CustomerNode* Next;
};
