#include <fstream>
#include <string>		// to use the function getline
#include <iomanip>		// for simplifying printing out 
#include "DoublyLinkedListOfRims.h"

void DoublyLinkedListOfRims::addRim(unsigned* lrn)
{
	std::string name, manufacturer, color, temp;
	int stock;
	float price, diameter, width;
	unsigned material;

	// We use two pointers one for head and another to point to new RimNode
	RimNode* LastRim = tail->Prev, *ptn;

	// We allocate new memory for the new RimNode
	ptn = new RimNode();

	/* We populate the new Rim Node */
	std::cout << "Please insert the attributes of the new Rim one by one: " << std::endl;
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
	std::cout << "Width (inches): ";
	std::cin >> width;
	while (std::cin.fail())
	{
		std::cout << "Error detected while giving the Width. Please insert the width in inches: ";

		std::cin.clear();				// clears the error flag
		std::cin.ignore(1000, '\n');	// ignore the next 1000 chars (including the cause of the error of the input)
		std::cin >> width;
	}
	std::cout << std::endl;
	std::cout << "Material (0 steel, 1 aluminium): ";
	std::cin >> material;
	while (std::cin.fail())
	{
		std::cout << "Error detected while giving the Material. Please insert the Material number (0 steel, 1 aluminium): ";

		std::cin.clear();				// clears the error flag
		std::cin.ignore(1000, '\n');	// ignore the next 1000 chars (including the cause of the error of the input)
		std::cin >> material;
	}
	std::cout << std::endl;
	std::cout << "Color: ";
	std::cin >> color;
	while (std::cin.fail())
	{
		std::cout << "Error detected while giving the Color. Please insert the Color: ";

		std::cin.clear();				// clears the error flag
		std::cin.ignore(1000, '\n');	// ignore the next 1000 chars (including the cause of the error of the input)
		std::cin >> color;
	}
	std::cout << std::endl;

	ptn->setArticleName(name);
	ptn->setArticleManufacturer(manufacturer);
	ptn->setStockOfArticle(stock);
	ptn->setDiameterOfArticle(diameter);
	ptn->setPriceOfArticle(price);
	ptn->setTypeOfArticle(1);
	ptn->setWidth(width);
	ptn->setMaterial(material);
	ptn->setColor(color);
	ptn->setID(lrn);

	// We insert new Tire to the end of the list 
	// Linking the new TireNode:
	tail->Prev = ptn;
	ptn->Next = tail;
	LastRim->Next = ptn;
	ptn->Prev = LastRim;
}

void DoublyLinkedListOfRims::deleteRim(void)
{
	std::string id;

	if (head->Next->getID() == tail->getID())
	{
		std::cout << "Nothing to delete the List of Rims is already empty" << std::endl;
	}
	else
	{
		std::cout << "Insert the ID of the Rim Article you want to remove: ";
		std::cin >> id;
		RimNode* Current = head;
		
		// transversal walk while we have not found the ID or we have not reach the dummyTail
		while (Current->getID() != id && Current->getID() != tail->getID())
		{
			Current = Current->Next;
		}

		if (Current->getID() == tail->getID()) // if we reached the dummyTail
		{
			std::cout << "The given Rim ID was not found in the List of Rims" << std::endl;
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
				RimNode* BeforeNode = Current->Prev;
				RimNode* AfterNode = Current->Next;

				delete Current;
				BeforeNode->Next = AfterNode;
				AfterNode->Prev = BeforeNode;
				std::cout << "The Article Rim with ID \"" << id << "\" was succesfully deleted." << std::endl;
			}
		}
	}
}

void DoublyLinkedListOfRims::displayRims(void)
{
	RimNode* Current = head->Next;	// We skip the dummyHead
	unsigned cw1 = 16, cw2 = 8, cw3 = 4, cw4 = 24;						// Column width1, widht2, width3
	if (Current->getID() == tail->getID())
	{
		std::cout << "Nothing to print, the List of Rims is Empty!" << std::endl;
	}
	else
	{
		std::cout << std::endl;
		std::cout << "------------------------------------------------------------------------------------" << std::endl;
		std::cout << std::setw(cw3) << "ID" << std::setw(cw4) << "Name" << std::setw(cw1) << "Manufacturer"	<< std::setw(cw2) << "Diam" 
		<< std::setw(cw2) << "Price" << std::setw(cw2) << "Width" << std::setw(cw3) << "Mat" << std::setw(cw2) << "Color" << std::endl;
		std::cout << "------------------------------------------------------------------------------------" << std::endl;
		while (Current->getID() != tail->getID())
		{
			std::cout << std::setw(cw3) << Current->getID() << std::setw(cw4) << Current->getArticleName() << std::setw(cw1) << Current->getArticleManufacturer()
				<< std::setw(cw2) << Current->getDiameterOfArticle() << std::setw(cw2) << Current->getPriceOfArticle()
				<< std::setw(cw2) << Current->getWidth() << std::setw(cw3) << Current->getMaterial() << std::setw(cw2) << Current->getColor() << std::endl;
			std::cout << "------------------------------------------------------------------------------------" << std::endl;
			Current = Current->Next;
		}
		std::cout << "*Diam: Diameter    *Mat: Material (0 steel, 1 aluminium)" << std::endl;
	}
}

void DoublyLinkedListOfRims::displayStock(void)
{
	RimNode* Current = head->Next;							// We skip the dummyHead
	unsigned cw1 = 16, cw2 = 8, cw3 = 4, cw4 = 24;			// Column widths
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
		std::cout << "ID begins with \"ri\" for Rims\t\t*Diam = Diameter" << std::endl;  // legend for abreviations
		std::cout << std::endl;
	}
}

void DoublyLinkedListOfRims::updateStock(void)
{
	RimNode* Current = head->Next;							// We skip the dummyHead
	std::string givenID;
	unsigned newStock;

	if (Current->getID() == tail->getID())
	{
		std::cout << std::endl;
		std::cout << "Nothing to update, the List of Rims is Empty!" << std::endl;
	}
	else
	{
		std::cout << "Please insert the ID of the Rim article whose stock you would like to update: ";
		std::cin >> givenID;

		while(Current->getID() != tail->getID() && Current->getID() != givenID)
		{
			Current = Current->Next;
		}
		if (Current->getID() == tail->getID())
		{
			std::cout << "The given Rim ID is not present in the List of Rims" << std::endl;
		}
		else
		{
			std::cout << "Insert the new stock value for the Rim with ID \"" << givenID << "\": ";
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

void DoublyLinkedListOfRims::filterRimsBySize(void)
{
	RimNode* Current = head->Next;		// We skip the dummyHead
	float givenSize;
	bool atLeastOneFound = false;

	std::cout << "Please insert the rim diameter you want to use as filter: ";
	std::cin >> givenSize;

	std::cout << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << " ID\tName\t\tManufature\tStock\tDiameter\tPrice\tWidth\tMaterial\tColor" << std::endl;
	std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	while (Current->getDiameterOfArticle() != tail->getDiameterOfArticle())
	{
		if (Current->getDiameterOfArticle() == givenSize)
		{
			atLeastOneFound = true;
			std::cout << " " << Current->getID() << " \t" << Current->getArticleName() << " \t" << Current->getArticleManufacturer()
				<< "\t\t" << Current->getStockOfArticle() << "\t" << Current->getDiameterOfArticle() << "\t\t" << Current->getPriceOfArticle()
				<< "\t" << Current->getWidth() << "\t" << Current->getMaterial() << " \t\t" << Current->getColor() << std::endl;
			std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
		}
		Current = Current->Next;
	}
	if (!atLeastOneFound)
	{
		std::cout << "No rims with the given diameter of \"" << givenSize << "\" where found." << std::endl;
	}
	std::cout << std::endl;
}

void DoublyLinkedListOfRims::loadFromFile(void)
{
	RimNode* tempRim, * beforeTemp;
	std::ifstream fromRimsFile;
	std::string id, name, manufacturer, color, trash;
	int stock;
	float diameter, price, width;
	unsigned type, material;
	// open file in read input mode
	fromRimsFile.open("rims.txt", std::ios::in);
	if (!fromRimsFile)
	{
		std::cout << "File \"tires.txt\" could not be opened" << std::endl;
	}
	else
	{
		getline(fromRimsFile, id);				// last line is an empty line in the file
		while (!fromRimsFile.eof() && id.length() != 0)
		{
			getline(fromRimsFile, name);
			getline(fromRimsFile, manufacturer);
			fromRimsFile >> stock;
			fromRimsFile >> diameter;
			fromRimsFile >> price;
			fromRimsFile >> type;
			fromRimsFile >> width;
			fromRimsFile >> material;
			getline(fromRimsFile, trash);
			getline(fromRimsFile, color);

			tempRim = new RimNode();
			tempRim->copyID(id);
			tempRim->setArticleName(name);
			tempRim->setArticleManufacturer(manufacturer);
			tempRim->setStockOfArticle(stock);
			tempRim->setDiameterOfArticle(diameter);
			tempRim->setPriceOfArticle(price);
			tempRim->setTypeOfArticle(type);
			tempRim->setWidth(width);
			tempRim->setMaterial(material);
			tempRim->setColor(color);
			/* We are inserting always at the tail */
			beforeTemp = tail->Prev;		// we use the previous of the tail
			// we adjust four links
			beforeTemp->Next = tempRim;
			tempRim->Next = tail;
			tempRim->Prev = beforeTemp;
			tail->Prev = tempRim;

			// the previous reading was getline(fromInvoicesFile, color) which takes also the new line char
			getline(fromRimsFile, id);
		}
		fromRimsFile.close();
	}
}

void DoublyLinkedListOfRims::saveToFile(void)
{
	RimNode* tempRim;
	std::ofstream toRimsFile;
	// opens file in mode write(out)
	toRimsFile.open("rims.txt", std::ofstream::out);			// we overwrite to save modifications
	if (!toRimsFile)
	{
		std::cout << "File \"rims.txt\" could not be created or opened" << std::endl;
	}
	else
	{
		tempRim = head->Next;
		while (tempRim->getID() != tail->getID())
		{
			toRimsFile << tempRim->getID() << std::endl << tempRim->getArticleName() << std::endl << tempRim->getArticleManufacturer() << std::endl
				<< tempRim->getStockOfArticle() << " " << tempRim->getDiameterOfArticle() << " " << tempRim->getPriceOfArticle() << " "
				<< tempRim->getTypeOfArticle() << " " << tempRim->getWidth() << " " << tempRim->getMaterial() << std::endl << tempRim->getColor() << std::endl;
			tempRim = tempRim->Next;
		}
		toRimsFile.close();
	}
}
