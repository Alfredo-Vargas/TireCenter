#include <iostream>
#include <string>
#include <ctime>
#include "InvoiceNode.h"

void InvoiceNode::setID(unsigned* lastInvoiceNumber)
{
	std::string prefix = "in";
	(*lastInvoiceNumber)++;
	id = prefix + std::to_string(*lastInvoiceNumber);  // this line requires the <string> header	
}

void InvoiceNode::copyID(std::string newID)
{
	id = newID;
}

void InvoiceNode::setDate(void)		// this function requires the ctime header
{
	// idea taken from: https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm
	// localtime was deprecated, he we used localtime_s instead

	// DATE IMPLEMENTATION FOR WINDOWS (uses localtime_s)
	time_t now = time(0);  // returns current time in seconds
	struct tm ltm;
	localtime_s(&ltm, &now);
	// tm* ltm = localtime(&now);
	date.setYear(1900 + ltm.tm_year);
	date.setMonth(1 + ltm.tm_mon);
	date.setDay(ltm.tm_mday);
	date.setHour(5 + ltm.tm_hour);
	date.setMinute(30 + ltm.tm_min);
	date.setSecond(ltm.tm_sec);


	// DATE IMPLEMENTATION FOR LINUX (uses localtime_r)
	/*
	time_t now = time(0);	// return current time in seconds
	struct tm ltm;
	localtime_r(&now, &ltm);
	date.setYear(1900 + ltm.tm_year);
	date.setMonth(1 + ltm.tm_mon);
	date.setDay(ltm.tm_mday);
	date.setHour(5 + ltm.tm_hour);
	date.setMinute(30 + ltm.tm_min);
	date.setSecond(ltm.tm_sec);
	*/
}

void InvoiceNode::copyDate(Date newDate)
{
	date.setYear(newDate.getYear());
	date.setMonth(newDate.getMonth());
	date.setDay(newDate.getDay());
	date.setHour(newDate.getHour());
	date.setMinute(newDate.getMinute());
	date.setSecond(newDate.getSecond());
}

void InvoiceNode::setCustomer(CustomerNode newCustomer)
{
	// Deep copy from Customer List to Invoice List
	customer = newCustomer;
	// We detacht the Customer from the List of Customers, it is now independent of the Customer List
	customer.Prev = nullptr;
	customer.Next = nullptr;
}
