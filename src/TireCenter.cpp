#include <iostream>
#include "TireCenter.h"

// Member functions:
void TireCenter::setName(std::string newName)
{
	name = newName;
}
void TireCenter::setAddress(std::string newAddress)
{
	address = newAddress;
}
void TireCenter::welcomeMessage( void )
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
unsigned TireCenter::logIn ( void )
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
unsigned TireCenter::mainMenu( void )
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
unsigned TireCenter::customerMenu(unsigned id)
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
unsigned TireCenter::articleMenu(unsigned id)
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
unsigned TireCenter::stockMenu(void)
{
	std::string wrong;		// wrong input
	unsigned ua;		// user action
	char* c;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "-----------------------------STOCK MENU-------------------------" << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "(1)\tDisplay Full Stock" << std::endl;
	std::cout << "(2)\tDisplay Stock of Tires" << std::endl;
	std::cout << "(3)\tDisplay Stock of Rims" << std::endl;
	std::cout << "(4)\tUpdate Stock of Tires" << std::endl;
	std::cout << "(5)\tUpdate Stock of Rims" << std::endl;
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
		if (wrong.length() != 1 || ua > 5)
		{
			std::cout << "Wrong option, please insert one of the above numbers: " << std::endl;
		}
	} while (wrong.length() != 1 || ua > 5);
	return ua;
}