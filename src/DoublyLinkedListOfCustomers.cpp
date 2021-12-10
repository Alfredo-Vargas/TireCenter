#include <fstream>
#include <string>
#include <iomanip>		// for simplifying printing out 
#include "DoublyLinkedListOfCustomers.h"

void DoublyLinkedListOfCustomers::addCustomer(unsigned* lcn)
{
	std::string id, firstname, lastname, address;
	unsigned type;

	CustomerNode* LastClient = tail->Prev, *ptn;
	ptn = new CustomerNode();

	/* We populate the new Customer Node */
	std::cout << "Please insert the firstname of the Customer: " << std::endl;
	std::cin.ignore();
	getline(std::cin, firstname);
	std::cout << "Please insert the lastname of the Customer: " << std::endl;
	getline(std::cin, lastname);
	std::cout << "Please insert the address of the Customer: " << std::endl;
	getline(std::cin, address);
	std::cout << "Insert 0 or 1. Is this Customer private (0) or corporate(1)?: " << std::endl;
	std::cin >> type;
	ptn->setID(lcn);
	ptn->setFirstName(firstname);
	ptn->setLastName(lastname);
	ptn->setAddress(address);
	ptn->setType(type);

	// We insert new Customer to the end of the list
	// Linking the new CustomerNode:
	tail->Prev = ptn;
	ptn->Next = tail;
	LastClient->Next = ptn;
	ptn->Prev = LastClient;
}

void DoublyLinkedListOfCustomers::deleteCustomer(void)
{
	std::string id;

	if (head->Next->getID() == tail->getID())
	{
		std::cout << "Nothing to delete the List of Customers is already empty" << std::endl;
	}
	else
	{
		std::cout << "Insert the ID of the Customer you want to remove: ";
		std::cin >> id;

		CustomerNode* Current = head;
		
		// transversal walk while we have not found the ID or we have not reach the dummyTail
		while (Current->getID() != id && Current->getID() != tail->getID())
		{
			Current = Current->Next;
		}

		if (Current->getID() == tail->getID()) // if we reached the dummyTail
		{
			std::cout << "The given Customer ID was not found in the List of Customers" << std::endl;
		}
		else
		{
			CustomerNode* BeforeNode = Current->Prev;
			CustomerNode* AfterNode = Current->Next;

			delete Current;
			BeforeNode->Next = AfterNode;
			AfterNode->Prev = BeforeNode;
			std::cout << "The Customer with ID \"" << id << "\" was succesfully deleted ." << std::endl;
		}
	}
}

void DoublyLinkedListOfCustomers::displayCustomers(void)
{
	CustomerNode* Current = head->Next;					// We skip the dummyHead
	unsigned cw1 = 16, cw2 = 36, cw3 = 4;				// Column width1, widht2, width3
	if (Current->getID() == tail->getID())
	{
		std::cout << "Nothing to print, the List of Customers is Empty!" << std::endl;
	}
	else
	{
		std::cout << std::endl;
		std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << std::setw(cw3) << "ID" << std::setw(cw1) << "FirstName" << std::setw(cw2) << "LastName/Email" << std::setw(cw2) << "Address"
			<< std::setw(cw1) << "Type" << std::endl;
		std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
		while (Current->getID() != tail->getID())
		{
			std::cout << std::setw(cw3) << Current->getID() << std::setw(cw1) << Current->getFirstName() << std::setw(cw2) << Current->getLastName()
				<< std::setw(cw2) << Current->getAddress() << std::setw(cw1) << Current->getType() << std::endl;
			std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
			Current = Current->Next;
		}
		std::cout << "Type (0 private, 1 corporate)" << std::endl;  // legend for abreviations
	}
}

void DoublyLinkedListOfCustomers::loadFromFile(void)
{
	CustomerNode* tempCustomer, *beforeTemp;
	std::ifstream fromCustomersFile;
	std::string id, firstname, lastname, address, temp_type;
	unsigned type;
	// open file in read input mode
	fromCustomersFile.open("customers.txt", std::ios::in);
	if (!fromCustomersFile)
	{
		std::cout << "File \"customers.txt\" could not be opened" << std::endl;
	}
	else
	{
		getline(fromCustomersFile, id);				// last line is an empty line in the file
		while (!fromCustomersFile.eof() && id.length() != 0)
		{
			tempCustomer = new CustomerNode();
			getline(fromCustomersFile, firstname);
			getline(fromCustomersFile, lastname);
			getline(fromCustomersFile, address);
			getline(fromCustomersFile, temp_type);
			type = (unsigned)temp_type[0];
			type = type - 48;						// ASCII int value conversion
			tempCustomer->copyID(id);
			tempCustomer->setFirstName(firstname);
			tempCustomer->setLastName(lastname);
			tempCustomer->setAddress(address);
			tempCustomer->setType(type);
			/* We are inserting always at the tail */
			beforeTemp = tail->Prev;		// we use the previous of the tail
			// we adjust four links
			beforeTemp->Next = tempCustomer;
			tempCustomer->Next = tail;
			tempCustomer->Prev = beforeTemp;
			tail->Prev = tempCustomer;

			getline(fromCustomersFile, id);
		}
		fromCustomersFile.close();
	}
}

void DoublyLinkedListOfCustomers::saveToFile(void)
{
	CustomerNode* tempCustomer;
	std::ofstream toCustomersFile;
	// opens file in mode write(out)
	toCustomersFile.open("customers.txt", std::ofstream::out);			// we overwrite to save modifications
	if (!toCustomersFile)
	{
		std::cout << "File \"customers.txt\" could not be created or opened" << std::endl;
	}
	else
	{
		tempCustomer = head->Next;
		while (tempCustomer->getID() != tail->getID())	
		{
			toCustomersFile << tempCustomer->getID() << std::endl; 
			toCustomersFile << tempCustomer->getFirstName() << std::endl;
			toCustomersFile << tempCustomer->getLastName() << std::endl;
			toCustomersFile << tempCustomer->getAddress() << std::endl; 
			toCustomersFile << tempCustomer->getType() << std::endl;
			tempCustomer = tempCustomer->Next;
		}
		toCustomersFile.close();
	}
}
