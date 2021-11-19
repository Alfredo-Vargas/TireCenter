#include <fstream>
#include <string>		// to use the function getline
#include <iomanip>		// to use the function setw (set width)
#include "DoublyLinkedListOfTires.h"

// head, tail and dummyHead and dummyTail are initialized with the following ID:
// 9998 and 9999 values for width are set to bare in mind that every insertion will be ordered

DoublyLinkedListOfTires::~DoublyLinkedListOfTires()
{

}

void DoublyLinkedListOfTires::addTire(unsigned* ltn)
{
	std::string name, manufacturer, temp;
	int stock;
	float price, diameter, width, height;
	char speedIndex;
	unsigned seasson;

	// We use two pointers one for tail and another to point to new TireNode
	TireNode* LastTire = tail->Prev, *ptn;

	// We allocate new memory for the new TireNode
	ptn = new TireNode();

	/* We populate the new Tire Node*/
	std::cout << "Please insert the attributes of the new Tire one by one: " << std::endl;
	std::cout << std::endl;
	std::cout << "Name: ";
	std::cin.ignore();		// to clear the input buffer of previous statements ('\n' of previous statements)
	getline(std::cin, name);
	std::cout << std::endl;
	std::cout << "Manufacturer: ";
	getline(std::cin, manufacturer);
	std::cout << std::endl;
	std::cout << "Stock: ";
	std::cin >> stock;
	/* We check if there is an error in the input or the value  */
	while (std::cin.fail())
	{
		std::cout << "Error detected while giving the Stock. Please insert an integer: ";

		std::cin.clear();				// clears the error flag
		std::cin.ignore(1000, '\n');	// ignore the next 1000 chars (including the cause of the error of the input)
		std::cin >> stock;
	}
	std::cout << std::endl;
	std::cout << "Diameter (milimeters): ";
	std::cin >> diameter;
	while (std::cin.fail())
	{
		std::cout << "Error detected while giving the Diameter. Please insert the diameter in milimeters of this new tire: ";

		std::cin.clear();				// clears the error flag
		std::cin.ignore(1000, '\n');	// ignore the next 1000 chars (including the cause of the error of the input)
		std::cin >> diameter;
	}
	std::cout << std::endl;
	std::cout << "Price (euros): ";
	std::cin >> price;
	while (std::cin.fail())
	{
		std::cout << "Error detected while giving the Price. Please insert the price in euro: ";

		std::cin.clear();				// clears the error flag
		std::cin.ignore(1000, '\n');	// ignore the next 1000 chars (including the cause of the error of the input)
		std::cin >> price;
	}
	std::cout << std::endl;
	std::cout << "Width (milimeters): ";
	std::cin >> width;
	while (std::cin.fail())
	{
		std::cout << "Error detected while giving the Width. Please insert the width in milimeters: ";

		std::cin.clear();				// clears the error flag
		std::cin.ignore(1000, '\n');	// ignore the next 1000 chars (including the cause of the error of the input)
		std::cin >> width;
	}
	std::cout << std::endl;
	std::cout << "Height (milimeters): ";
	std::cin >> height;
	while (std::cin.fail())
	{
		std::cout << "Error detected while giving the Height. Please insert the height in milimeters: ";

		std::cin.clear();				// clears the error flag
		std::cin.ignore(1000, '\n');	// ignore the next 1000 chars (including the cause of the error of the input)
		std::cin >> height;
	}
	std::cout << std::endl;
	std::cout << "Speed Index (single letter from A - Y): ";
	std::cin >> speedIndex;
	while (std::cin.fail())
	{
		std::cout << "Error detected while giving the Speed Index. Please insert the a single letter from A - Y: ";

		std::cin.clear();				// clears the error flag
		std::cin.ignore(1000, '\n');	// ignore the next 1000 chars (including the cause of the error of the input)
		std::cin >> speedIndex;
	}
	std::cout << std::endl;
	std::cout << "Seasson (0 winter, 1 summer): ";
	std::cin >> seasson;
	while (std::cin.fail())
	{
		std::cout << "Error detected while giving the Seasson. Please insert 0 for winter and 1 for summer: ";

		std::cin.clear();				// clears the error flag
		std::cin.ignore(1000, '\n');	// ignore the next 1000 chars (including the cause of the error of the input)
		std::cin >> seasson;
	}
	std::cout << std::endl;
	ptn->setArticleName(name);
	ptn->setArticleManufacturer(manufacturer);
	ptn->setStockOfArticle(stock);
	ptn->setDiameterOfArticle(diameter);
	ptn->setPriceOfArticle(price);
	ptn->setTypeOfArticle(0);
	ptn->setWidth(width);
	ptn->setHeight(height);
	ptn->setSpeedIndex(speedIndex);
	ptn->setSeasson(seasson);
	ptn->setID(ltn);

	// We insert new Tire to the end of the list 
	// Linking the new TireNode:
	tail->Prev = ptn;
	ptn->Next = tail;
	LastTire->Next = ptn;
	ptn->Prev = LastTire;
}

void DoublyLinkedListOfTires::deleteTire(void)
{
	std::string id;

	if (head->Next->getID() == tail->getID())
	{
		std::cout << "Nothing to delete the List of Tires is already empty" << std::endl;
	}
	else
	{
		std::cout << "Insert the ID of the Tire Article you want to remove: ";
		std::cin >> id;

		TireNode* Current = head;
		
		// transversal walk while we have not found the ID or we have not reach the dummyTail
		while (Current->getID() != id && Current->getID() != tail->getID())
		{
			Current = Current->Next;
		}

		if (Current->getID() == tail->getID()) // if we reached the dummyTail
		{
			std::cout << "The given Tire ID was not found in the List of Tires" << std::endl;
		}
		else
		{
			if (Current->getStockOfArticle() != 0)
			{
				std::cout << "The Article with ID \"" << Current->getID() << "\" cannot be deleted. The Stock value of the Article is not zero." << std::endl; 
				std::cout << "Please empty the Stock of the Article with ID \"" << Current->getID() << "\" before deleting it." << std::endl; 
			}
			else
			{
				TireNode* BeforeNode = Current->Prev;
				TireNode* AfterNode = Current->Next;

				delete Current;
				BeforeNode->Next = AfterNode;
				AfterNode->Prev = BeforeNode;
				std::cout << "The Article Tire with ID \"" << id << "\" was succesfully deleted." << std::endl;
			}
		}
	}
}

void DoublyLinkedListOfTires::displayTires(void)
{
	TireNode* Current = head->Next;							// We skip the dummyHead
	unsigned cw1 = 16, cw2 = 8, cw3 = 4, cw4 = 24, cw5 = 12;			// Column widths
	if (Current->getID() == tail->getID())
	{
		std::cout << std::endl;
		std::cout << "Nothing to print, the List of Tires is Empty!" << std::endl;
	}
	else
	{
		std::cout << std::endl;
		std::cout << "----------------------------------------------------------------------------------------" << std::endl;
		std::cout << std::setw(cw3) << "ID" << std::setw(cw4) << "Name" << std::setw(cw1) << "Manufacturer" << std::setw(cw2) << "Diam"
		 << std::setw(cw2) << "Price" << std::setw(cw2) << "Width" << std::setw(cw2) << "Height" << std::setw(cw3) << "SI" << std::setw(cw3) << "Se" << std::endl;
		std::cout << "----------------------------------------------------------------------------------------" << std::endl;
		while (Current->getID() != tail->getID())
		{
			std::cout << std::setw(cw3) << Current->getID() << std::setw(cw4) << Current->getArticleName() << std::setw(cw1) << Current->getArticleManufacturer()
				<<  std::setw(cw2) << Current->getDiameterOfArticle() << std::setw(cw2) << Current->getPriceOfArticle()
				<< std::setw(cw2) << Current->getWidth() << std::setw(cw2) << Current->getHeight() << std::setw(cw3) << Current->getSpeedIndex() << std::setw(cw3) << Current->getSeasson() << std::endl;
			std::cout << "----------------------------------------------------------------------------------------" << std::endl;
			Current = Current->Next;
		}
		std::cout << "*Diam: Diameter    *SI: Speed Index    *Se: Seasson (0 winter, 1 summer)" << std::endl;  // legend for abreviations
	}
}

void DoublyLinkedListOfTires::displayStock(void)
{
	TireNode* Current = head->Next;							// We skip the dummyHead
	unsigned cw1 = 16, cw2 = 8, cw3 = 4, cw4 = 24, cw5 = 12;			// Column widths
	if (Current->getID() == tail->getID())
	{
		std::cout << std::endl;
		std::cout << "Nothing to print, the List of Tires is Empty!" << std::endl;
	}
	else
	{
		std::cout << std::endl;
		std::cout << "------------------------------------------------------------------------------" << std::endl;
		std::cout << std::setw(cw3) << "ID" << std::setw(cw4) << "Name" << std::setw(cw1) << "Manufacturer" << std::setw(cw2) << "Diam"
		 << std::setw(cw2) << "Price" << std::setw(cw2) << "Stock" << std::endl;
		std::cout << "------------------------------------------------------------------------------" << std::endl;
		while (Current->getID() != tail->getID())
		{
			std::cout << std::setw(cw3) << Current->getID() << std::setw(cw4) << Current->getArticleName() << std::setw(cw1) << Current->getArticleManufacturer()
				<<  std::setw(cw2) << Current->getDiameterOfArticle() << std::setw(cw2) << Current->getPriceOfArticle()
				<< std::setw(cw2) << Current->getStockOfArticle() << std::endl;
			std::cout << "------------------------------------------------------------------------------" << std::endl;
			Current = Current->Next;
		}
		std::cout << "ID begins with \"ti\" for Tires\t\t*Diam = Diameter" << std::endl;  // legend for abreviations
		std::cout << std::endl;
	}
}

void DoublyLinkedListOfTires::updateStock(void)
{
	TireNode* Current = head->Next;							// We skip the dummyHead
	std::string givenID;
	unsigned newStock;

	if (Current->getID() == tail->getID())
	{
		std::cout << std::endl;
		std::cout << "Nothing to update, the List of Tires is Empty!" << std::endl;
	}
	else
	{
		std::cout << "Please insert the ID of the Tire article whose stock you would like to update: ";
		std::cin >> givenID;

		while(Current->getID() != tail->getID() && Current->getID() != givenID)
		{
			Current = Current->Next;
		}
		if (Current->getID() == tail->getID())
		{
			std::cout << "The given Tire ID is not present in the List of Tires" << std::endl;
		}
		else
		{
			std::cout << "Insert the new stock value for the Tire with ID \"" << givenID << "\": ";
			std::cin >> newStock;	
			while (std::cin.fail())
			{
				std::cout << "Error detected while giving the Stock. Please insert an integer: ";

				std::cin.clear();				// clears the error flag
				std::cin.ignore(1000, '\n');	// ignore the next 1000 chars (including the cause of the error of the input)
				std::cin >> newStock;
			}
			Current->setStockOfArticle(newStock);
			std::cout << "The stock was updated succesfully." << std::endl;
		}
	}
}

void DoublyLinkedListOfTires::filterTiresBySize(void)
{
	TireNode* Current = head->Next;		// We skip the dummyHead
	unsigned cw1 = 16, cw2 = 8, cw3 = 4;						// Column width1, widht2
	float givenSize;
	bool atLeastOneFound = false;

	std::cout << "Please insert the tire diameter you want to use as filter: ";
	std::cin >> givenSize;

	std::cout << std::endl;
	std::cout << "------------------------------------------------------------------------------------" << std::endl;
	std::cout << std::setw(cw3) << "ID" << std::setw(cw1) << "Name" << std::setw(cw1) << "Manufacturer" << std::setw(cw2) << "Stock"
		<< std::setw(cw2) << "Diam" << std::setw(cw2) << "Price" << std::setw(cw2) << "Width" << std::setw(cw2) << "Height" << std::setw(cw3) << "SI" << std::setw(cw3) << "Se" << std::endl;
	std::cout << "------------------------------------------------------------------------------------" << std::endl;

	while (Current->getID() != tail->getID())
	{
		if (Current->getDiameterOfArticle() == givenSize)
		{
			atLeastOneFound = true;
			std::cout << std::setw(cw3) << Current->getID() << std::setw(cw1) << Current->getArticleName() << std::setw(cw1) << Current->getArticleManufacturer()
				<< std::setw(cw2) << Current->getStockOfArticle() << std::setw(cw2) << Current->getDiameterOfArticle() << std::setw(cw2) << Current->getPriceOfArticle()
				<< std::setw(cw2) << Current->getWidth() << std::setw(cw2) << Current->getHeight() << std::setw(cw3) << Current->getSpeedIndex() << std::setw(cw3) << Current->getSeasson() << std::endl;
			std::cout << "------------------------------------------------------------------------------------" << std::endl;
			Current = Current->Next;
		}
		Current = Current->Next;
	}
	if (!atLeastOneFound)
	{
		std::cout << "No tires with the given diameter of \"" << givenSize << "\" where found." << std::endl;
	}
	std::cout << std::endl;
}

void DoublyLinkedListOfTires::loadFromFile(void)
{
	TireNode* tempTire, * beforeTemp;
	std::ifstream fromTiresFile;
	std::string id, name, manufacturer, trash;
	int stock;
	float diameter, price, width, height;
	char speedIndex;
	unsigned type, seasson;
	// open file in read input mode
	fromTiresFile.open("tires.txt", std::ios::in);
	if (!fromTiresFile)
	{
		std::cout << "File \"tires.txt\" could not be opened" << std::endl;
	}
	else
	{
		getline(fromTiresFile, id);			// last line is an empty line in the file
		while (!fromTiresFile.eof() && id.length() != 0)
		{
			getline(fromTiresFile, name);
			getline(fromTiresFile, manufacturer);
			fromTiresFile >> stock;
			fromTiresFile >> diameter;
			fromTiresFile >> price;
			fromTiresFile >> type;
			fromTiresFile >> width;
			fromTiresFile >> height;
			fromTiresFile >> speedIndex;
			fromTiresFile >> seasson;

			tempTire = new TireNode();
			tempTire->copyID(id);
			tempTire->setArticleName(name);
			tempTire->setArticleManufacturer(manufacturer);
			tempTire->setStockOfArticle(stock);
			tempTire->setDiameterOfArticle(diameter);
			tempTire->setPriceOfArticle(price);
			tempTire->setTypeOfArticle(type);
			tempTire->setWidth(width);
			tempTire->setHeight(height);
			tempTire->setSpeedIndex(speedIndex);
			tempTire->setSeasson(seasson);
			/* We are inserting always at the tail */
			beforeTemp = tail->Prev;		// we use the previous of the tail
			// we adjust four links
			beforeTemp->Next = tempTire;
			tempTire->Next = tail;
			tempTire->Prev = beforeTemp;
			tail->Prev = tempTire;

			getline(fromTiresFile, trash);	// to ignore the last '\n'
			getline(fromTiresFile, id);
		}
		fromTiresFile.close();
	}
}

void DoublyLinkedListOfTires::saveToFile(void)
{
	TireNode* tempTire;
	std::ofstream toTiresFile;
	// opens file in mode write(out)
	toTiresFile.open("tires.txt", std::ofstream::out);			// we overwrite to save modifications
	if (!toTiresFile)
	{
		std::cout << "File \"tires.txt\" could not be created or opened" << std::endl;
	}
	else
	{
		tempTire = head->Next;
		while (tempTire->getID() != tail->getID())
		{
			toTiresFile << tempTire->getID() << std::endl << tempTire->getArticleName() << std::endl << tempTire->getArticleManufacturer() << std::endl
				<< tempTire->getStockOfArticle() << " " << tempTire->getDiameterOfArticle() << " " << tempTire->getPriceOfArticle() << " "
				<< tempTire->getTypeOfArticle() << " " << tempTire->getWidth() << " " << tempTire->getHeight() << " " << tempTire->getSpeedIndex() << " "
				<< tempTire->getSeasson() << std::endl;
			tempTire = tempTire->Next;
		}
		toTiresFile.close();
	}
}
