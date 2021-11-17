#include <fstream>
#include <string>
#include <iomanip>		// for simplifying printing out 
#include "DoublyLinkedListOfInvoices.h"
#include "DoublyLinkedListOfCustomers.h"

DoublyLinkedListOfInvoices::~DoublyLinkedListOfInvoices()
{

}

void DoublyLinkedListOfInvoices::placeOrder(unsigned* lin, DoublyLinkedListOfTires* listOfTires, DoublyLinkedListOfRims* listOfRims, DoublyLinkedListOfCustomers* listOfCustomers)
{
	TireNode* pointerToTire, *tireToBuy, *beforeTire, *tireHead, *tireTail;
	RimNode* pointerToRim, *rimToBuy, *beforeRim, *rimHead, *rimTail;
	CustomerNode* pointerToCustomer;
	std::string customerID, tireID, rimID;
	unsigned userAction, quantity, auxiliar;
	float totalPrice = 0;

	// We use two pointers one for tail and another to point to new Invoice
	InvoiceNode* LastInvoice = tail->Prev, *ptn;

	std::cout << "Please insert the ID of the Customer who wants to Place an Order: ";
	std::cin >> customerID;

	// We start the traversal walk from the beginning of the list of Customers skipping the dummyHead
	pointerToCustomer = listOfCustomers->head->Next;	

	while (pointerToCustomer->getID() != customerID && pointerToCustomer->getID() != listOfCustomers->tail->getID())
	{
		pointerToCustomer = pointerToCustomer->Next;
	}
	// End of traversal walk

	if (pointerToCustomer->getID() == listOfCustomers->tail->getID())
	{
		std::cout << "The given ID of the Customer has not been found. Please add the Customer to the register before placing an order" << std::endl;
	}
	else
	{
		// We Allocate new memory for the new InvoiceNode
		ptn = new InvoiceNode();

		// Allocate memory for the dummy head and tail of the cart list of Tires
		tireHead = new TireNode();
		tireTail = new TireNode();
		ptn->cartOfTires.head = tireHead;
		ptn->cartOfTires.tail = tireTail;
		ptn->cartOfTires.head->Next = ptn->cartOfTires.tail;
		ptn->cartOfTires.head->Prev = nullptr;
		ptn->cartOfTires.tail->Prev = ptn->cartOfTires.head;
		ptn->cartOfTires.tail->Next = nullptr;
		ptn->cartOfTires.head->copyID("ti9998");
		ptn->cartOfTires.tail->copyID("ti9999");

		// Allocate memory for the dummy head and tail of the cart list of Rims
		rimHead = new RimNode();
		rimTail = new RimNode();
		ptn->cartOfRims.head = rimHead;
		ptn->cartOfRims.tail = rimTail;
		ptn->cartOfRims.head->Next = ptn->cartOfRims.tail;
		ptn->cartOfRims.head->Prev = nullptr;
		ptn->cartOfRims.tail->Prev = ptn->cartOfRims.head;
		ptn->cartOfRims.tail->Next = nullptr;
		ptn->cartOfRims.head->copyID("ri9998");
		ptn->cartOfRims.tail->copyID("ri9999");


		/* We populate the new Invoice Node */
		ptn->setID(lin);		// we generate a new ID
		ptn->setDate();			// we set the current date
		ptn->setCustomer(*pointerToCustomer);	// we make a deep copy of the customer from the List Of costumers

		// We insert new Invoice to the end of the list
		// Linking the new InvoiceNode:
		tail->Prev = ptn;
		ptn->Next = tail;
		LastInvoice->Next = ptn;
		ptn->Prev = LastInvoice;

		do
		{
			std::cout << "Type \"0\" to close the order. Whould you like to see the List of Tires(\"1\") or List of Rims(\"2\")?: ";
			std::cin >> userAction;
			switch (userAction)
			{
			case(1):
			{
				listOfTires->displayTires();
				std::cout << "Type the ID of the article you would like to add to the Shopping Cart and its quantity: ";
				std::cin >> tireID >> quantity;
				pointerToTire = listOfTires->head->Next;	// we skip the dummyHead
				while (pointerToTire->getID() != tireID && pointerToTire->getID() != listOfTires->tail->getID())
				{
					pointerToTire = pointerToTire->Next;
				}
				if (pointerToTire->getID() == listOfTires->tail->getID())
				{
					std::cout << "The given Tire ID \"" << tireID << "\" was not found." << std::endl;
				}
				else
				{
					if (pointerToTire->getStockOfArticle() < quantity)
					{
						std::cout << "The amount requested exceeds the stock, please specify a lower quantity" << std::endl;
					}
					else
					{
						// We update the Stock when placing an order
						auxiliar = pointerToTire->getStockOfArticle() - quantity;
						pointerToTire->setStockOfArticle(auxiliar);
	
						// We alocate new TireNode for each Tire the Customer wants to buy
						tireToBuy = new TireNode();
						*tireToBuy = *pointerToTire;			 // deep copy of the tire to buy
						tireToBuy->setStockOfArticle(quantity);  // here this number represents the quantity and NOT the stock
						beforeTire = ptn->cartOfTires.tail->Prev;
						// We wire 4 links up
						beforeTire->Next = tireToBuy;
						tireToBuy->Prev = beforeTire;
						tireToBuy->Next = ptn->cartOfTires.tail;
						ptn->cartOfTires.tail->Prev = tireToBuy;
						totalPrice += tireToBuy->getPriceOfArticle() * tireToBuy->getStockOfArticle();
					}
				}
				break;
			}
			case(2):
			{
				listOfRims->displayRims();
				std::cout << "Type the ID of the article you would like to add to the Shopping Cart and its quantity: ";
				std::cin >> rimID >> quantity;
				pointerToRim = listOfRims->head->Next;	// we skip the dummyHead
				while (pointerToRim->getID() != rimID && pointerToRim->getID() != listOfRims->tail->getID())
				{
					pointerToRim = pointerToRim->Next;
				}
				if (pointerToRim->getID() == listOfRims->tail->getID())
				{
					std::cout << "The given Rim ID \"" << rimID << "\" was not found." << std::endl;
				}
				else
				{
					if (pointerToRim->getStockOfArticle() < quantity)
					{
						std::cout << "The amount requested exceeds the stock, please specify a lower quantity" << std::endl;
					}
					else
					{
						// We update the Stock when placing an order
						auxiliar = pointerToRim->getStockOfArticle() - quantity;
						pointerToRim->setStockOfArticle(auxiliar);

						// We alocate new RimNode for each Rim the Customer wants to buy
						rimToBuy = new RimNode();
						*rimToBuy = *pointerToRim;				// deep copy of the rim to buy
						rimToBuy->setStockOfArticle(quantity);  // here this number represents the quantity and NOT the stock
						beforeRim = ptn->cartOfRims.tail->Prev;
						// We wire 4 links up
						beforeRim->Next = rimToBuy;
						rimToBuy->Prev = beforeRim;
						rimToBuy->Next = ptn->cartOfRims.tail;
						ptn->cartOfRims.tail->Prev = rimToBuy;

						totalPrice += rimToBuy->getPriceOfArticle() * rimToBuy->getStockOfArticle();
					}
				}
				break;
			}
			}
		} while (userAction != 0);

		std::cout << "The total price of the order is: " << totalPrice << std::endl;
	}
}

void DoublyLinkedListOfInvoices::displayInvoices(void)
{
	InvoiceNode* Current = head->Next;		// We skip the dummyHead
	TireNode* tempTire;
	RimNode* tempRim;
	std::string fullname, fulldate, customerType;
	unsigned cw1 = 16, cw2 = 10, cw3 = 6, cw4 = 24;				// Column width1, widht2, width3, width4
	float subtotal, totalPrice, discount;
	if (Current->getID() == tail->getID())
	{
		std::cout << "Nothing to print, the List of Invoices is Empty!" << std::endl;
	}
	else
	{
		subtotal = 0;
		totalPrice = 0;
		discount = 0;
		while (Current->getID() != tail->getID())
		{
			fullname = Current->getCustomer().getFirstName() + " " + Current->getCustomer().getLastName();
			fulldate = std::to_string(Current->getDate().getYear()) + "-" + std::to_string(Current->getDate().getMonth()) + "-" + std::to_string(Current->getDate().getDay())
				+ " " + std::to_string(Current->getDate().getHour()) + ":" + std::to_string(Current->getDate().getMinute()) + ":" + std::to_string(Current->getDate().getSecond());
			if (Current->getCustomer().getType() == 0)
			{
				customerType = "private";
			}
			else
			{
				customerType = "corporate";
			}
			std::cout << std::endl;
			std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
			std::cout << std::setw(cw3) << "ID" << std::setw(cw4) << "Customer Full Name" << std::setw(cw4) << "Date of the Order" << std::setw(cw4) << "Delivery Address" << std::setw(cw4) << "Customer Type" << std::endl;
			std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
			std::cout << std::setw(cw3) << "LIST OF ARTICLES ORDERED: " << std::endl;
			std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
			std::cout << std::setw(cw3) << Current->getID() << std::setw(cw4) << fullname << std::setw(cw4) << fulldate << std::setw(cw4) << Current->getCustomer().getAddress() << std::setw(cw4) << customerType << std::endl;
			std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
			std::cout << std::setw(cw1) << "Name" << std::setw(cw3) << "ID" << std::setw(cw1)  << "Quantity" << std::setw(cw1) << "Unitary Price" << std::setw(cw1) << "Subtotal" << std::endl;
			std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
			tempTire = Current->cartOfTires.head->Next;
			while (tempTire->getID() != Current->cartOfTires.tail->getID())
			{
				subtotal = tempTire->getPriceOfArticle() * tempTire->getStockOfArticle();
				std::cout << std::setw(cw1) << tempTire->getArticleName() << std::setw(cw3) << tempTire->getID() << std::setw(cw1) << tempTire->getStockOfArticle() << std::setw(cw1) << tempTire->getPriceOfArticle()
					 << std::setw(cw1) << std::setprecision (2) << std::fixed << subtotal << std::endl;
				std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
				totalPrice = totalPrice + subtotal;
				tempTire = tempTire->Next;
			}
			tempRim = Current->cartOfRims.head->Next;
			while (tempRim->getID() != Current->cartOfRims.tail->getID())
			{
				subtotal = tempRim->getPriceOfArticle() * tempRim->getStockOfArticle();
				std::cout << std::setw(cw1) << tempRim->getArticleName() << std::setw(cw3) << tempRim->getID() << std::setw(cw1) << tempRim->getStockOfArticle() << std::setw(cw1) << tempRim->getPriceOfArticle()
					 << std::setw(cw1) << std::setprecision (2) << std::fixed << subtotal << std::endl;
				std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
				totalPrice = totalPrice + subtotal;
				tempRim = tempRim->Next;
			}
			std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
			std::cout << "The total price of invoice \"" << Current->getID() << "\" is : " << std::setprecision(2) << std::fixed << totalPrice << std::endl;
			std::cout << std::endl;
			Current = Current->Next;
			subtotal = 0;
			totalPrice = 0;
			discount = 0;
		}
	}
}

void DoublyLinkedListOfInvoices::loadFromFile(void)
{
	InvoiceNode* tempInvoice, *beforeTemp;
	TireNode* tempTire, *beforeTire, *tireHead, *tireTail;
	RimNode* tempRim, *beforeRim, *rimHead, *rimTail;
	std::ifstream fromInvoicesFile;
	std::string invoiceID, customerID, articleID, firstname, lastname, address, name, manufacturer, color, trash;
	unsigned year, month, day, hour, minute, second, customerType, articleType, seasson, material;
	int stock;
	float diameter, price, width, height;
	char speedIndex;
	Date date;
	CustomerNode currentCustomer;
	// open file in read input mode
	fromInvoicesFile.open("invoices.txt", std::ios::in);
	if (!fromInvoicesFile)
	{
		std::cout << "File \"invoices.txt\" could not be opened" << std::endl;
	}
	else
	{
		getline(fromInvoicesFile, invoiceID);				// last line is an empty line in the file
		while (!fromInvoicesFile.eof() && invoiceID.length() != 0)
		{
			tempInvoice = new InvoiceNode();
			fromInvoicesFile >> year >> month >> day >> hour >> minute >> second;
			getline(fromInvoicesFile, trash);
			getline(fromInvoicesFile, customerID);
			getline(fromInvoicesFile, firstname);
			getline(fromInvoicesFile, lastname);
			getline(fromInvoicesFile, address);
			fromInvoicesFile >> customerType;

			date.setYear(year);
			date.setMonth(month);
			date.setDay(day);
			date.setHour(hour);
			date.setMinute(minute);
			date.setSecond(second);
			tempInvoice->copyID(invoiceID);
			tempInvoice->copyDate(date);

			currentCustomer.copyID(customerID);
			currentCustomer.setFirstName(firstname);
			currentCustomer.setLastName(lastname);
			currentCustomer.setAddress(address);
			currentCustomer.setType(customerType);
			tempInvoice->setCustomer(currentCustomer);

			// We allocate memory for the dummy Nodes for the cartOfTires
			tireHead = new TireNode();
			tireHead->copyID("ti9998");
			tireTail = new TireNode();
			tireTail->copyID("ti9999");
			tireHead->Prev = nullptr;
			tireHead->Next = tireTail;
			tireTail->Prev = tireHead;
			tireTail->Next = nullptr;
			tempInvoice->cartOfTires.head = tireHead;
			tempInvoice->cartOfTires.tail = tireTail;

			// We allocate memory for the dummy Nodes for the cartOfRims
			rimHead = new RimNode();
			rimHead->copyID("ri9998");
			rimTail = new RimNode();
			rimTail->copyID("ri9999");
			rimHead->Prev = nullptr;
			rimHead->Next = rimTail;
			rimTail->Prev = rimHead;
			rimTail->Next = nullptr;
			tempInvoice->cartOfRims.head = rimHead;
			tempInvoice->cartOfRims.tail = rimTail;


			fromInvoicesFile >> articleID;
			while (articleID != "EndOfShoppingCartOfTires")
			{
				fromInvoicesFile >> name >> manufacturer >> stock >> diameter >> price >> articleType >> width >> height >> speedIndex >> seasson;
				tempTire = new TireNode();
				tempTire->copyID(articleID);
				tempTire->setArticleName(name);
				tempTire->setArticleManufacturer(manufacturer);
				tempTire->setStockOfArticle(stock);
				tempTire->setDiameterOfArticle(diameter);
				tempTire->setPriceOfArticle(price);
				tempTire->setTypeOfArticle(articleType);
				tempTire->setWidth(width);
				tempTire->setHeight(height);
				tempTire->setSpeedIndex(speedIndex);
				tempTire->setSeasson(seasson);
				/* We are inserting always at the tail */
				beforeTire = tireTail->Prev;		// we use the previous of the tail
				// we adjust four links
				beforeTire->Next = tempTire;
				tempTire->Next = tireTail;
				tempTire->Prev = beforeTire;
				tireTail->Prev = tempTire;

				fromInvoicesFile >> articleID;
			}
			fromInvoicesFile >> articleID;
			while (articleID != "EndOfShoppingCartOfRims")
			{
				fromInvoicesFile >> name;
				fromInvoicesFile >> manufacturer;
				fromInvoicesFile >> stock;
				fromInvoicesFile >> diameter;
				fromInvoicesFile >> price;
				fromInvoicesFile >> articleType;
				fromInvoicesFile >> width;
				fromInvoicesFile >> material;
				fromInvoicesFile >> color;

				tempRim = new RimNode();
				tempRim->copyID(articleID);
				tempRim->setArticleName(name);
				tempRim->setArticleManufacturer(manufacturer);
				tempRim->setStockOfArticle(stock);
				tempRim->setDiameterOfArticle(diameter);
				tempRim->setPriceOfArticle(price);
				tempRim->setTypeOfArticle(articleType);
				tempRim->setWidth(width);
				tempRim->setMaterial(material);
				tempRim->setColor(color);

				/* We are inserting always at the tail */
				beforeRim = tempInvoice->cartOfRims.tail->Prev;		// we use the previous of the tail
				// we adjust four links
				beforeRim->Next = tempRim;
				tempRim->Next = tempInvoice->cartOfRims.tail;
				tempRim->Prev = beforeRim;
				tempInvoice->cartOfRims.tail->Prev = tempRim;

				fromInvoicesFile >> articleID;
			}

			beforeTemp = tail->Prev;
			// we adjust four links of the List of Invoices
			// fromInvoicesFile >> articleID;
			beforeTemp->Next = tempInvoice;
			tempInvoice->Next = tail;
			tempInvoice->Prev = beforeTemp;
			tail->Prev = tempInvoice;

			getline(fromInvoicesFile, trash);
			getline(fromInvoicesFile, invoiceID);				// last line is an empty line in the file
		}

		fromInvoicesFile.close();
	}

}

void DoublyLinkedListOfInvoices::saveToFile(void)
{
	InvoiceNode* tempInvoice;
	TireNode* tempTire;
	RimNode* tempRim;
	std::ofstream toInvoicesFile;
	// opens file in mode write(out)	
	toInvoicesFile.open("invoices.txt", std::ofstream::out);			// we overwrite to save modifications
	if (!toInvoicesFile)
	{
		std::cout << "File \"invoices.txt\" could not be created or opened" << std::endl;
	}
	else
	{
		tempInvoice = head->Next;
		while (tempInvoice->getID() != tail->getID())
		{
			toInvoicesFile << tempInvoice->getID() << std::endl; 
			toInvoicesFile << tempInvoice->getDate().getYear() << " " << tempInvoice->getDate().getMonth() << " " << tempInvoice->getDate().getDay() << " "
				<< tempInvoice->getDate().getHour() << " " << tempInvoice->getDate().getMinute() << " " << tempInvoice->getDate().getSecond() << std::endl;
			toInvoicesFile << tempInvoice->getCustomer().getID() << std::endl;
			toInvoicesFile << tempInvoice->getCustomer().getFirstName() << std::endl;
			toInvoicesFile << tempInvoice->getCustomer().getLastName() << std::endl;
			toInvoicesFile << tempInvoice->getCustomer().getAddress() << std::endl;
			toInvoicesFile << tempInvoice->getCustomer().getType() << std::endl;

			// We check if cartOfTires is empty:
			tempTire = tempInvoice->cartOfTires.head->Next;		// walker
			if (tempTire->getID() == tempInvoice->cartOfTires.tail->getID())
			{
				toInvoicesFile << "EndOfShoppingCartOfTires" << std::endl;
			}
			else
			{
				while (tempTire->getID() != tempInvoice->cartOfTires.tail->getID())
				{
					toInvoicesFile << tempTire->getID() << " " << tempTire->getArticleName() << " " << tempTire->getArticleManufacturer()
						<< " " << tempTire->getStockOfArticle() << " " << tempTire->getDiameterOfArticle() << " " << tempTire->getPriceOfArticle() << " "
						<< tempTire->getTypeOfArticle() << " " << tempTire->getWidth() << " " << tempTire->getHeight() << " " << tempTire->getSpeedIndex() << " "
						<< tempTire->getSeasson() << std::endl;
					tempTire = tempTire->Next;
				}
				toInvoicesFile << "EndOfShoppingCartOfTires" << std::endl;
			}

			// We check if cartOfRims is empty:
			tempRim = tempInvoice->cartOfRims.head->Next;		// walker
			if (tempRim->getID() == tempInvoice->cartOfRims.tail->getID())
			{
				toInvoicesFile << "EndOfShoppingCartOfRims" << std::endl;
			}
			else
			{
				while (tempRim->getID() != tempInvoice->cartOfRims.tail->getID())
				{
					toInvoicesFile << tempRim->getID() << " " << tempRim->getArticleName() << " " << tempRim->getArticleManufacturer()
						<< " " << tempRim->getStockOfArticle() << " " << tempRim->getDiameterOfArticle() << " " << tempRim->getPriceOfArticle() << " "
						<< tempRim->getTypeOfArticle() << " " << tempRim->getWidth() << " " << tempRim->getMaterial() << " " << tempRim->getColor() << " " << std::endl;
					tempRim = tempRim->Next;
				}
				toInvoicesFile << "EndOfShoppingCartOfRims" << std::endl;
			}
			tempInvoice = tempInvoice->Next;
		}
		toInvoicesFile.close();
	}
}
