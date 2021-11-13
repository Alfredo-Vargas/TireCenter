#include <fstream>
#include <iomanip>		// for simplifying printing out 
#include "DoublyLinkedListOfRims.h"

// head, tail and dummyHead and dummyTail are initialized with the following ID:
// 9998 and 9999 values for width are set to bare in mind that every insertion will be ordered

DoublyLinkedListOfRims::~DoublyLinkedListOfRims()
{

}

void DoublyLinkedListOfRims::addRim(unsigned* lrn)
{
	std::string name, manufacturer, color;
	int stock;
	float price, diameter, width;
	unsigned material;

	// We use two pointers one for head and another to point to new TireNode
	RimNode* LastRim = tail->Prev, *ptn;

	// We allocate new memory for the new RimNode
	ptn = new RimNode();

	/* We populate the new Rim Node */
	std::cout << "Respect the format when inserting the entries (space separated), material is 0 for steel and 1 for aluminium :" << std::endl;
	std::cout << "name manufacturer stock diameter price(float) width(float) material color" << std::endl;
	std::cin >> name >> manufacturer >> stock >> diameter >> price >> width >> material >> color;
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
			RimNode* BeforeNode = Current->Prev;
			RimNode* AfterNode = Current->Next;

			delete Current;
			BeforeNode->Next = AfterNode;
			AfterNode->Prev = BeforeNode;
			std::cout << "The Article Rim with ID \"" << id << "\" was succesfully deleted." << std::endl;
		}
	}
}

void DoublyLinkedListOfRims::displayRims(void)
{
	RimNode* Current = head->Next;	// We skip the dummyHead
	unsigned cw1 = 16, cw2 = 8, cw3 = 4;						// Column width1, widht2, width3
	if (Current->getID() == tail->getID())
	{
		std::cout << "Nothing to print, the List of Rims is Empty!" << std::endl;
	}
	else
	{
		std::cout << std::endl;
		std::cout << "------------------------------------------------------------------------------------" << std::endl;
		std::cout << std::setw(cw3) << "ID" << std::setw(cw1) << "Name" << std::setw(cw1) << "Manufacturer" << std::setw(cw2) << "Stock"
			<< std::setw(cw2) << "Diam" << std::setw(cw2) << "Price" << std::setw(cw2) << "Width" << std::setw(cw3) << "Mat" << std::setw(cw2) << "Color" << std::endl;
		std::cout << "------------------------------------------------------------------------------------" << std::endl;
		while (Current->getID() != tail->getID())
		{
			std::cout << std::setw(cw3) << Current->getID() << std::setw(cw1) << Current->getArticleName() << std::setw(cw1) << Current->getArticleManufacturer()
				<< std::setw(cw2) << Current->getStockOfArticle() << std::setw(cw2) << Current->getDiameterOfArticle() << std::setw(cw2) << Current->getPriceOfArticle()
				<< std::setw(cw2) << Current->getWidth() << std::setw(cw3) << Current->getMaterial() << std::setw(cw2) << Current->getColor() << std::endl;
			std::cout << "------------------------------------------------------------------------------------" << std::endl;
			Current = Current->Next;
		}
		std::cout << "*Diam: Diameter    *Mat: Material (0 steel, 1 aluminium)" << std::endl;
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
	std::string id, name, manufacturer, color;
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
		fromRimsFile >> id;				// last line is an empty line in the file
		while (!fromRimsFile.eof() && id.length() != 0)
		{
			fromRimsFile >> name;
			fromRimsFile >> manufacturer;
			fromRimsFile >> stock;
			fromRimsFile >> diameter;
			fromRimsFile >> price;
			fromRimsFile >> type;
			fromRimsFile >> width;
			fromRimsFile >> material;
			fromRimsFile >> color;

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

			fromRimsFile >> id;
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
			toRimsFile << tempRim->getID() << " " << tempRim->getArticleName() << " " << tempRim->getArticleManufacturer() << " "
				<< tempRim->getStockOfArticle() << " " << tempRim->getDiameterOfArticle() << " " << tempRim->getPriceOfArticle() << " "
				<< tempRim->getTypeOfArticle() << " " << tempRim->getWidth() << " " << tempRim->getMaterial() << " " << tempRim->getColor() << " " << std::endl;
			tempRim = tempRim->Next;
		}
		toRimsFile.close();
	}
}