#include <iostream>
#include "Article.h"

// So far no need of a constructor

// Member functions:
void Article::setArticleName(std::string newName)
{
	name = newName;
}
void Article::setArticleManufacturer(std::string newManufacturer)
{
	manufacturer = newManufacturer;
}
void Article::setStockOfArticle(int newStock)
{
	stock = newStock;
}
void Article::setDiameterOfArticle(float newDiameter)
{
	diameter = newDiameter;
}
void Article::setPriceOfArticle(float newPrice)
{
	price = newPrice;
}

void Article::setTypeOfArticle(unsigned newType)	// 0 for tire 1 for rim
{
	type = newType;
}