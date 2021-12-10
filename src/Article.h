#pragma once
#include <iostream>

class Article
{
private:
	std::string name;
	std::string manufacturer;
	unsigned stock = 0;		// initialized to zero to avoid warning of type.6
	float diameter = 0;		// initialized to zero to avoid warning of type.6
	float price = 0;		// initialized to zero to avoid warning of type.6
	unsigned type = 0;		// to be used outside the class Article (Tire or Rim) initialized to zero to avoid warning of type.6
public:
	std::string getArticleName() { return name; }
	void setArticleName(std::string);

	std::string getArticleManufacturer() { return manufacturer; }
	void setArticleManufacturer(std::string);

	unsigned getStockOfArticle() { return stock; }
	void setStockOfArticle(unsigned);

	float getDiameterOfArticle() { return diameter; }
	void setDiameterOfArticle(float);

	float getPriceOfArticle() { return price; }
	void setPriceOfArticle(float);

	unsigned getTypeOfArticle() { return type; }
	void setTypeOfArticle(unsigned);
};