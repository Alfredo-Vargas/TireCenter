#pragma once
#include "Article.h"

// to inherit all the attributes and methods from the class Article
class TireNode : public Article
{
private:// height is missing (correct here and all dependencies)
	std::string id;
	float width;	// given in milimeters unlike Rims (given in inches)
	float height;
	char speedIndex;
	unsigned seasson;
public:
	float getWidth() { return width; }
	void setWidth(float);
	void copyID(std::string);		// this is needed when want to retrieve data from a file!

	float getHeight() { return height; }
	void setHeight(float);

	char getSpeedIndex() { return speedIndex; }
	void setSpeedIndex(char);

	unsigned getSeasson() { return seasson; }
	void setSeasson(unsigned);

	std::string getID() { return id; }
	void setID(unsigned*);

	TireNode* Prev;
	TireNode* Next;
};