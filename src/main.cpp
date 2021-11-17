/*  CACHE MEMORY CHANGES THE PERFORMANCE OF OPERATIONS OF ARRAYS VS 
	LINKED LISTS https://www.youtube.com/watch?v=DyG9S9nAlUM&ab_channel=Computerphile
	*/
#include <iostream>
#include <fstream>	// to write and read data from or to a file
#include <string>	// to read line by line from a file
#include "DoublyLinkedListOfTires.h"  // idea taken from tutorial: https://www.youtube.com/watch?v=fR6UIEQE930&t=322s&ab_channel=BradleySward
#include "DoublyLinkedListOfRims.h"
#include "DoublyLinkedListOfCustomers.h"
#include "DoublyLinkedListOfInvoices.h"

void welcomeMessage(void);
unsigned logIn(void);
unsigned mainMenu(void);
unsigned customerMenu(unsigned);
unsigned articleMenu(unsigned);
unsigned stockMenu(void);
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

	DoublyLinkedListOfTires listOfTires;			// structure to store tires.
	TireNode dummyTireHead;
	TireNode dummyTireTail;

	DoublyLinkedListOfRims listOfRims;				// structure to store rims.
	RimNode dummyRimHead;
	RimNode dummyRimTail;

	DoublyLinkedListOfCustomers listOfCustomers;	// structure to store customers.
	CustomerNode dummyCustomerHead;
	CustomerNode dummyCustomerTail;
		
	DoublyLinkedListOfInvoices listOfInvoices;		// structure to store invoices.
	InvoiceNode dummyInvoiceHead;
	InvoiceNode dummyInvoiceTail;

	/* We populate the dummy variables of the List of Tires */
	linkDummyTireNodes(&listOfTires, &dummyTireHead, &dummyTireTail);

	/* We populate the dummy variables of the List of Rims */
	linkDummyRimNodes(&listOfRims, &dummyRimHead, &dummyRimTail);

	/* We populate the dummy variables of the List of Customers */
	linkDummyCustomerNodes(&listOfCustomers, &dummyCustomerHead, &dummyCustomerTail);

	/* We populate the dummy variables of the List of Invoices */
	linkDummyInvoiceNodes(&listOfInvoices, &dummyInvoiceHead, &dummyInvoiceTail);

	// If the database is empty we start from zero, otherwise the numbers below are initialized from a file
	loadIndexFile(&lastTireNumber, &lastRimNumber, &lastCustomerNumber, &lastInvoiceNumber);
	listOfTires.loadFromFile();
	listOfRims.loadFromFile();
	listOfCustomers.loadFromFile();
	listOfInvoices.loadFromFile();

	welcomeMessage();

	idFlag = logIn();

	do
	{
		userAction = mainMenu();
		switch (userAction)
		{
		case(1):
		{
			do
			{
				userAction = customerMenu(idFlag);
				userAction = userAction == 0 ? 9 : userAction;   // change 0 to 9 to not exit the whole program but just the customer menu
				switch (userAction)
				{
				case(1):
				{
					listOfCustomers.addCustomer(&lastCustomerNumber);
					break;
				}
				case(2):
				{
					listOfCustomers.displayCustomers();
					break;
				}
				case(3):
				{
					listOfCustomers.deleteCustomer();
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
				userAction = articleMenu(idFlag);
				userAction = userAction == 0 ? 9 : userAction;   // change 0 to 9 to not exit the whole program but just the customer menu
				switch (userAction)
				{
				case(1):
				{
					listOfTires.displayTires();
					break;
				}
				case(2):
				{
					listOfRims.displayRims();
					break;
				}
				case(3):
				{
					listOfTires.filterTiresBySize();
					break;
				}
				case(4):
				{
					listOfRims.filterRimsBySize();
					break;
				}
				case(5):
				{
					listOfTires.addTire(&lastTireNumber);
					break;
				}
				case(6):
				{
					listOfRims.addRim(&lastRimNumber);
					break;
				}
				case(7):
				{
					listOfTires.deleteTire();
					break;
				}
				case(8):
				{
					listOfRims.deleteRim();
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
				userAction = stockMenu();
				userAction = userAction == 0 ? 9 : userAction;   // change 0 to 9 to not exit the whole program but just the customer menu
				switch (userAction)
				{
				case(1):
				{
					// function call
					break;
				}
				case(2):
				{
					// function call
					break;
				}
				}
			} while (userAction != 9);
			break;
		}
		case(4):
		{
			listOfInvoices.placeOrder(&lastInvoiceNumber, &listOfTires, &listOfRims, &listOfCustomers);
			break;
		}
		case(5):
		{
			listOfInvoices.displayInvoices();
			break;
		}
		}
	} while (userAction != 0);

	/* We save the data before closing the application */
	listOfTires.saveToFile();
	listOfRims.saveToFile();
	listOfCustomers.saveToFile();
	listOfInvoices.saveToFile();
	updateIndexFile(lastTireNumber, lastRimNumber, lastCustomerNumber, lastInvoiceNumber);

	return 0;
}

void welcomeMessage(void)
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << " **********   **   *******     ********         ******    ********   ****     **   **********   ********   *******  " << std::endl;
	std::cout << "/////**///   /**  /**////**   /**/////         **////**  /**/////   /**/**   /**  /////**///   /**/////   /**////** " << std::endl;
	std::cout << "    /**      /**  /**   /**   /**             **    //   /**        /**//**  /**      /**      /**        /**   /** " << std::endl;
	std::cout << "    /**      /**  /*******    /*******       /**         /*******   /** //** /**      /**      /*******   /*******  " << std::endl;
	std::cout << "    /**      /**  /**///**    /**////        /**         /**////    /**  //**/**      /**      /**////    /**///**  " << std::endl;
	std::cout << "    /**      /**  /**  //**   /**            //**    **  /**        /**   //****      /**      /**        /**  //** " << std::endl;
	std::cout << "    /**      /**  /**   //**  /********       //******   /********  /**    //***      /**      /********  /**   //**" << std::endl;
	std::cout << "    //       //   //     //   ////////         //////    ////////   //      ///       //       ////////   //     // " << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}

unsigned logIn(void)
{
	std::string wrong;
	char* c;
	unsigned id;
	do
	{
		std::cout << "Please insert \"0\" to log in as an Employee or \"1\" to log in as the Owner: ";
		std::cin >> wrong;
		if (wrong.length() != 1)
		{
			id = 2;
		}
		else
		{
			c = const_cast<char*>(wrong.c_str());  // we point to the std::string object
			id = (unsigned)c[0];				   // the decimal values from ascii of 0 and 1 are 48 & 49
			id = id - 48;						   // convert from char ascii value to decimal value
		}
		std::cout << std::endl;
	} while (id != 0 && id != 1);

	return id;
}

unsigned mainMenu(void)
{
	std::string wrong;	// wrong input
	unsigned ua;	// user action
	char* c;

	std::cout << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "----------------------------MAIN MENU---------------------------" << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "(1)\tCustomer" << std::endl;
	std::cout << "(2)\tArticles" << std::endl;
	std::cout << "(3)\tStock" << std::endl;
	std::cout << "(4)\tPlace Order" << std::endl;
	std::cout << "(5)\tDisplay Invoice" << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "(0)\tExit the program" << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "Insert one of the above numbers to proceed: ";

	do	// code to validate user input in main menu
	{
		std::cin >> wrong;						   // we assume the user input is wrong
		c = const_cast<char*>(wrong.c_str());  // we point to the std::string object
		ua = (unsigned)c[0];
		ua = ua - 48;						   // we convert char value to decimal
		if (wrong.length() != 1 || ua > 5)
		{
			std::cout << "Wrong option, please insert one of the above numbers." << std::endl;
		}
	} while (wrong.length() != 1 || ua > 5); // here ends code to validate user input in main menu
	return ua;
}

unsigned customerMenu(unsigned id)
{
	std::string wrong;		// wrong input
	unsigned ua;		// user action
	unsigned n = 2;		// auxiliary variable to make distincion between Employee and Owner.
	char* c;
	std::cout << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "--------------------------CUSTOMER MENU-------------------------" << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "(1)\tAdd Customer" << std::endl;
	std::cout << "(2)\tDisplay Customer" << std::endl;
	if (id == 1)
	{
		n++;
		std::cout << "(3)\tDelete Customer" << std::endl;
	}
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "(0)\tBack to Main Menu" << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "Insert one of the above numbers to proceed: ";
	do
	{
		std::cin >> wrong;
		c = const_cast<char*>(wrong.c_str());  // we point to the std::string object
		ua = (unsigned)c[0];				   // the decimal value of the ascii char will be assigned
		ua = ua - 48;
		if (wrong.length() != 1 || ua > n)
		{
			std::cout << "Wrong option, please insert one of the above numbers: " << std::endl;
		}
	} while (wrong.length() != 1 || ua > n);
	return ua;
}

unsigned articleMenu(unsigned id)
{
	std::string wrong;		// wrong input
	unsigned ua;		// user action
	unsigned n = 4;		// auxiliary variable to make distincion between Employee and Owner.
	char* c;
	std::cout << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "---------------------------ARTICLE MENU-------------------------" << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "(1)\tShow Tires" << std::endl;
	std::cout << "(2)\tShow Rims" << std::endl;
	std::cout << "(3)\tFilter Tires by Size" << std::endl;
	std::cout << "(4)\tFilter Rims by Size" << std::endl;
	if (id == 1)
	{
		n = n + 4;
		std::cout << "(5)\tAdd Tire" << std::endl;
		std::cout << "(6)\tAdd Rim" << std::endl;
		std::cout << "(7)\tDelete Tire" << std::endl;
		std::cout << "(8)\tDelete Rim" << std::endl;
	}
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "(0)\tBack to Main Menu" << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "Insert one of the above numbers to proceed: ";
	do
	{
		std::cin >> wrong;
		c = const_cast<char*>(wrong.c_str());  // we point to the std::string object
		ua = (unsigned)c[0];				   // the decimal value of the ascii char will be assigned
		ua = ua - 48;
		if (wrong.length() != 1 || ua > n)
		{
			std::cout << "Wrong option, please insert one of the above numbers: " << std::endl;
		}
	} while (wrong.length() != 1 || ua > n);
	return ua;
}

unsigned stockMenu(void)
{
	std::string wrong;		// wrong input
	unsigned ua;		// user action
	char* c;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "-----------------------------STOCK MENU-------------------------" << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "(1)\tDisplay Stock" << std::endl;
	std::cout << "(2)\tUpdate Stock" << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "(0)\tBack to Main Menu" << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << "Insert one of the above numbers to proceed: ";
	do
	{
		std::cin >> wrong;
		c = const_cast<char*>(wrong.c_str());  // we point to the std::string object
		ua = (unsigned)c[0];				   // the decimal value of the ascii char will be assigned
		ua = ua - 48;
		if (wrong.length() != 1 || ua > 2)
		{
			std::cout << "Wrong option, please insert one of the above numbers: " << std::endl;
		}
	} while (wrong.length() != 1 || ua > 2);
	return ua;
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

