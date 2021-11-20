/*  CACHE MEMORY CHANGES THE PERFORMANCE OF OPERATIONS OF ARRAYS VS 
	LINKED LISTS https://www.youtube.com/watch?v=DyG9S9nAlUM&ab_channel=Computerphile
*/
#include <iostream>
#include <fstream>	// to write and read data from or to a file
#include <string>	// to read line by line from a file
//#include "DoublyLinkedListOfTires.h"  // idea taken from tutorial: https://www.youtube.com/watch?v=fR6UIEQE930&t=322s&ab_channel=BradleySward
//#include "DoublyLinkedListOfRims.h"
//#include "DoublyLinkedListOfCustomers.h"
//#include "DoublyLinkedListOfInvoices.h"
#include "TireCenter.h"

void linkDummyTireNodes(DoublyLinkedListOfTires*, TireNode*, TireNode*);
void linkDummyRimNodes(DoublyLinkedListOfRims*, RimNode*, RimNode*);
void linkDummyCustomerNodes(DoublyLinkedListOfCustomers*, CustomerNode*, CustomerNode*);
void linkDummyInvoiceNodes(DoublyLinkedListOfInvoices*, InvoiceNode*, InvoiceNode*);
void loadIndexFile(unsigned*, unsigned*, unsigned*, unsigned*);
void updateIndexFile(unsigned, unsigned, unsigned, unsigned);

int main(void)
{
	unsigned idFlag;				// Flag to determine if Employee or Owner logs in.
	unsigned userAction;			// Number to Register desirable action of the User.
	unsigned lastTireNumber;		// To keep track of the ID for the different tires.
	unsigned lastRimNumber;			// To keep track of the ID for the different rims.
	unsigned lastCustomerNumber;	// To keep track of the ID for the different customers.
	unsigned lastInvoiceNumber;		// To keep track of the ID for the different invoices.

	TireCenter myTireCenter;						// we declare an instance of TireCenter

	//DoublyLinkedListOfTires listOfTires;			// structure to store tires.
	TireNode dummyTireHead;
	TireNode dummyTireTail;

	//DoublyLinkedListOfRims listOfRims;				// structure to store rims.
	RimNode dummyRimHead;
	RimNode dummyRimTail;

	//DoublyLinkedListOfCustomers listOfCustomers;	// structure to store customers.
	CustomerNode dummyCustomerHead;
	CustomerNode dummyCustomerTail;
		
	//DoublyLinkedListOfInvoices listOfInvoices;		// structure to store invoices.
	InvoiceNode dummyInvoiceHead;
	InvoiceNode dummyInvoiceTail;

	/* We populate the dummy variables of the List of Tires */
	linkDummyTireNodes(&myTireCenter.listOfTires, &dummyTireHead, &dummyTireTail);
	//linkDummyTireNodes(&listOfTires, &dummyTireHead, &dummyTireTail);

	/* We populate the dummy variables of the List of Rims */
	linkDummyRimNodes(&myTireCenter.listOfRims, &dummyRimHead, &dummyRimTail);
	//linkDummyRimNodes(&listOfRims, &dummyRimHead, &dummyRimTail);

	/* We populate the dummy variables of the List of Customers */
	linkDummyCustomerNodes(&myTireCenter.listOfCustomers, &dummyCustomerHead, &dummyCustomerTail);
	//linkDummyCustomerNodes(&listOfCustomers, &dummyCustomerHead, &dummyCustomerTail);

	/* We populate the dummy variables of the List of Invoices */
	linkDummyInvoiceNodes(&myTireCenter.listOfInvoices, &dummyInvoiceHead, &dummyInvoiceTail);
	//linkDummyInvoiceNodes(&listOfInvoices, &dummyInvoiceHead, &dummyInvoiceTail);

	// If the database is empty we start from zero, otherwise the numbers below are initialized from a file
	loadIndexFile(&lastTireNumber, &lastRimNumber, &lastCustomerNumber, &lastInvoiceNumber);
	myTireCenter.listOfTires.loadFromFile();
	myTireCenter.listOfRims.loadFromFile();
	myTireCenter.listOfCustomers.loadFromFile();
	myTireCenter.listOfInvoices.loadFromFile();

	myTireCenter.welcomeMessage();

	idFlag = myTireCenter.logIn();

	do
	{
		userAction = myTireCenter.mainMenu();
		switch (userAction)
		{
		case(1):
		{
			do
			{
				userAction = myTireCenter.customerMenu(idFlag);
				userAction = userAction == 0 ? 9 : userAction;   // change 0 to 9 to not exit the whole program but just the customer menu
				switch (userAction)
				{
				case(1):
				{
					myTireCenter.listOfCustomers.addCustomer(&lastCustomerNumber);
					break;
				}
				case(2):
				{
					myTireCenter.listOfCustomers.displayCustomers();
					break;
				}
				case(3):
				{
					myTireCenter.listOfCustomers.deleteCustomer();
					break;
				}
				}
			} while (userAction != 9);

			break;
		}
		case(2):
		{
			do
			{
				userAction = myTireCenter.articleMenu(idFlag);
				userAction = userAction == 0 ? 9 : userAction;   // change 0 to 9 to not exit the whole program but just the customer menu
				switch (userAction)
				{
				case(1):
				{
					myTireCenter.listOfTires.displayTires();
					break;
				}
				case(2):
				{
					myTireCenter.listOfRims.displayRims();
					break;
				}
				case(3):
				{
					myTireCenter.listOfTires.filterTiresBySize();
					break;
				}
				case(4):
				{
					myTireCenter.listOfRims.filterRimsBySize();
					break;
				}
				case(5):
				{
					myTireCenter.listOfTires.addTire(&lastTireNumber);
					break;
				}
				case(6):
				{
					myTireCenter.listOfRims.addRim(&lastRimNumber);
					break;
				}
				case(7):
				{
					myTireCenter.listOfTires.deleteTire();
					break;
				}
				case(8):
				{
					myTireCenter.listOfRims.deleteRim();
					break;
				}
				}
			} while (userAction != 9);
			break;
		}
		case(3):
		{
			do
			{
				userAction = myTireCenter.stockMenu();
				userAction = userAction == 0 ? 9 : userAction;   // change 0 to 9 to not exit the whole program but just the customer menu
				switch (userAction)
				{
				case(1):
				{
					myTireCenter.listOfTires.displayStock();
					myTireCenter.listOfRims.displayStock();
					break;
				}
				case(2):
				{
					myTireCenter.listOfTires.displayStock();
					break;
				}
				case(3):
				{
					myTireCenter.listOfRims.displayStock();
					break;
				}
				case(4):
				{
					myTireCenter.listOfTires.updateStock();
					break;
				}
				case(5):
				{
					myTireCenter.listOfRims.updateStock();
					break;
				}
				}
			} while (userAction != 9);
			break;
		}
		case(4):
		{
			myTireCenter.listOfInvoices.placeOrder(&lastInvoiceNumber, &myTireCenter.listOfTires, &myTireCenter.listOfRims, &myTireCenter.listOfCustomers);
			break;
		}
		case(5):
		{
			myTireCenter.listOfInvoices.displayInvoices();
			break;
		}
		}
	} while (userAction != 0);

	/* We save the data before closing the application */
	myTireCenter.listOfTires.saveToFile();
	myTireCenter.listOfRims.saveToFile();
	myTireCenter.listOfCustomers.saveToFile();
	myTireCenter.listOfInvoices.saveToFile();
	updateIndexFile(lastTireNumber, lastRimNumber, lastCustomerNumber, lastInvoiceNumber);

	return 0;
}

void linkDummyTireNodes(DoublyLinkedListOfTires* ptr_list, TireNode* phead, TireNode* ptail)
{
	unsigned headID = 9997, tailID = 9998;
	// Six links 
	ptr_list->head = phead;
	ptr_list->tail = ptail;
	phead->Next = ptail;
	phead->Prev = nullptr;
	ptail->Prev = phead;
	ptail->Next = nullptr;

	// We set unreal values to make ordered insertion easy!!!

	// dummyHead population
	phead->setID(&headID);			// will get ID "ti9998"
	phead->setArticleName("Aaaa");
	phead->setArticleManufacturer("Aaaa");
	phead->setStockOfArticle(0);
	phead->setDiameterOfArticle(0);
	phead->setPriceOfArticle(0);
	phead->setTypeOfArticle(0);
	phead->setWidth(0);
	phead->setHeight(0);
	phead->setSpeedIndex('A');
	phead->setSeasson(0);		// 0 is the minimum value and means winter

	// dummyTail population
	ptail->setID(&tailID);			// will get ID "ti9999"
	ptail->setArticleName("Zzzz");
	ptail->setArticleManufacturer("Zzzz");
	ptail->setStockOfArticle(9999);
	ptail->setDiameterOfArticle(9999);
	ptail->setPriceOfArticle(9999);
	ptail->setTypeOfArticle(0);
	ptail->setWidth(9999);
	ptail->setHeight(9999);
	ptail->setSpeedIndex('Z');
	ptail->setSeasson(1);		// 1 is the minimum value and means summer
}

void linkDummyRimNodes(DoublyLinkedListOfRims* ptr_list, RimNode* phead, RimNode* ptail)
{
	unsigned headID = 9997, tailID = 9998;
	// Six links 
	ptr_list->head = phead;
	ptr_list->tail = ptail;
	phead->Next = ptail;
	phead->Prev = nullptr;
	ptail->Prev = phead;
	ptail->Next = nullptr;

	// We set unreal values to make ordered insertion easy!!!

	// dummyHead population
	phead->setID(&headID);			// will get ID "ri9998"
	phead->setArticleName("Aaaa");
	phead->setArticleManufacturer("Aaaa");
	phead->setStockOfArticle(0);
	phead->setDiameterOfArticle(0);
	phead->setPriceOfArticle(0);
	phead->setTypeOfArticle(0);
	phead->setWidth(0);
	phead->setMaterial(0);		// 0 is the minimum value and means steel
	phead->setColor("Aaaa");

	// dummyTail population
	ptail->setID(&tailID);			// will get ID "ri9999"
	ptail->setArticleName("Zzzz");
	ptail->setArticleManufacturer("Zzzz");
	ptail->setStockOfArticle(9999);
	ptail->setDiameterOfArticle(9999);
	ptail->setPriceOfArticle(9999);
	ptail->setTypeOfArticle(0);
	ptail->setWidth(9999);
	ptail->setMaterial(1);		// 1 is the maximum value and means aluminium
	ptail->setColor("Zzzz");
}

void linkDummyCustomerNodes(DoublyLinkedListOfCustomers* ptr_list, CustomerNode* phead, CustomerNode* ptail)
{
	unsigned headID = 9997, tailID = 9998;
	// Six links 
	ptr_list->head = phead;
	ptr_list->tail = ptail;
	phead->Next = ptail;
	phead->Prev = nullptr;
	ptail->Prev = phead;
	ptail->Next = nullptr;

	// We set unreal values to make ordered insertion easy!!!
	// dummyHead population
	phead->setID(&headID);			// will get ID "ci9998"
	phead->setFirstName("Aaaa");
	phead->setLastName("Aaaa");
	phead->setAddress("Aaaa");
	phead->setType(0);		// is the minimum value and means private

	// dummyTail population
	ptail->setID(&tailID);			// will get ID "ci9999"
	ptail->setFirstName("Zzzz");
	ptail->setLastName("Zzzz");
	ptail->setAddress("Zzzz");
	ptail->setType(1);		// 1 is the maximum value and means corporate
}

void linkDummyInvoiceNodes(DoublyLinkedListOfInvoices* ptr_list, InvoiceNode* phead, InvoiceNode* ptail)
{
	unsigned headID = 9997, tailID = 9998;
	// Six links 
	ptr_list->head = phead;
	ptr_list->tail = ptail;
	phead->Next = ptail;
	phead->Prev = nullptr;
	ptail->Prev = phead;
	ptail->Next = nullptr;

	// We set unreal values to make ordered insertion easy!!!
	// dummyHead population
	phead->setID(&headID);			// will get ID "in9998"

	// dummyTail population
	ptail->setID(&tailID);			// will get ID "in9999"
}

void updateIndexFile(unsigned ti, unsigned ri, unsigned ci, unsigned ii)
{
	std::ofstream toIndexFile;
	toIndexFile.open("index.txt", std::ofstream::out);					// we overwrite to save modifications
	if (!toIndexFile)
	{
		std::cout << "File \"index.txt\" could not be created or opened" << std::endl;
	}
	else
	{
		toIndexFile << ti << " " << ri << " " << ci << " " << ii;
		toIndexFile.close();
	}
}

void loadIndexFile(unsigned* pti, unsigned* pri, unsigned* pci, unsigned* pii)
{
	std::ifstream fromIndexFile;
	fromIndexFile.open("index.txt", std::ios::in);
	if (!fromIndexFile)
	{
		std::cout << "File \"index.txt\" could not be opened" << std::endl;
	}
	else
	{
		while (!fromIndexFile.eof())
		{
			fromIndexFile >> *pti >> *pri >> *pci >> *pii;
		}
		fromIndexFile.close();
	}
}
