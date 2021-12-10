#pragma once
#include "Article.h"

// to inherit all attributes and methods from the class Article
class RimNode : public Article
{
private:
	std::string id;
	std::string color;
	float width = 0;	   // given in inches unlike Tires (given in milimeters) Initialized to avoid warning type.6
	unsigned material = 0; // if (0 is steel, 1 is aluminium) Initialized to avoid warning type.6

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

	RimNode* Prev = {};
	RimNode* Next = {};
};
