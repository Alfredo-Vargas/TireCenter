#pragma once
#include <iostream>

class Article
{
private:
	std::string name;
	std::string manufacturer;
	int stock;
	float diameter;	
	float price;
	unsigned type;	// to be used outside the class Article (Tire or Rim)
public:
	std::string getArticleName() { return name; }
	void setArticleName(std::string);

	std::string getArticleManufacturer() { return manufacturer; }
	void setArticleManufacturer(std::string);

	int getStockOfArticle() { return stock; }
	void setStockOfArticle(int);

	float getDiameterOfArticle() { return diameter; }
	void setDiameterOfArticle(float);

	float getPriceOfArticle() { return price; }
	void setPriceOfArticle(float);

	unsigned getTypeOfArticle() { return type; }
	void setTypeOfArticle(unsigned);
};