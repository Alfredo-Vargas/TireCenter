#include <iostream>
#include <string>		// to concatenate the ID prefix with an incremental number;
#include "TireNode.h"

// Member functions
void TireNode::setWidth(float newWidth)
{
	width = newWidth;
}

void TireNode::copyID(std::string newID)
{
	id = newID;
}

void TireNode::setHeight(float newHeight)
{
	height = newHeight;
}

void TireNode::setSpeedIndex(char newSpeedIndex)
{
	speedIndex = newSpeedIndex;
}

void TireNode::setSeasson(unsigned newSeasson)
{
	seasson = newSeasson;
}

void TireNode::setID(unsigned* lastTireNumber)
{
	std::string prefix = "ti";
	(*lastTireNumber)++;
	id = prefix + std::to_string(*lastTireNumber);  // this line requires the <string> header
}