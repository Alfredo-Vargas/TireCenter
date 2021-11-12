#include <iostream>
#include <string>		// to concatenate the ID prefix with an incremental number;
#include "RimNode.h"

// Member functions

void RimNode::setWidth(float newWidth)
{
	width = newWidth;
}

void RimNode::setMaterial(unsigned newMaterial)
{
	material = newMaterial;
}

void RimNode::setColor(std::string newColor)
{
	color = newColor;
}

void RimNode::setID(unsigned* lastRimNumber)
{
	std::string prefix = "ri";
	(*lastRimNumber)++;
	id = prefix + std::to_string(*lastRimNumber);  // this line requires the <string> header
}

void RimNode::copyID(std::string newID)
{
	id = newID;
}
