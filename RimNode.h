#pragma once
#include "Article.h"

// to inherit all attributes and methods from the class Article
class RimNode : public Article
{
private:
	std::string id;
	std::string color;
	float width;	   // given in inches unlike Tires (given in milimeters)
	unsigned material; // if (0 is steel, 1 is aluminium)

public:
	float getWidth() { return width; }
	void setWidth(float);

	unsigned getMaterial() { return material; }
	void setMaterial(unsigned);

	std::string getColor() { return color; }
	void setColor(std::string);

	std::string getID() { return id; }
	void setID(unsigned*);
	void copyID(std::string);		// this is needed when want to retrieve data from a file!

	RimNode* Prev;
	RimNode* Next;
};
