#include <iostream>
#include <string>
#include "CustomerNode.h"

void CustomerNode::setID(unsigned* lastCustomerNumber)
{
	std::string prefix = "ci";
	(*lastCustomerNumber)++;
	id = prefix + std::to_string(*lastCustomerNumber);  // this line requires the <string> header
}

void CustomerNode::copyID(std::string newID)
{
	id = newID;
}

void CustomerNode::setFirstName(std::string newFirstName)
{
	firstname = newFirstName;
}

void CustomerNode::setLastName(std::string newLastName)
{
	lastname = newLastName;
}

void CustomerNode::setAddress(std::string newAddress)
{
	address = newAddress;
}

void CustomerNode::setType(unsigned newType)
{
	type = newType;
}
