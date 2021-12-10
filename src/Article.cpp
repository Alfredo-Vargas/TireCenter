#include <iostream>
#include "Article.h"

// Member functions:
void Article::setArticleName(std::string newName)
{
	name = newName;
}
void Article::setArticleManufacturer(std::string newManufacturer)
{
	manufacturer = newManufacturer;
}
void Article::setStockOfArticle(unsigned newStock)
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