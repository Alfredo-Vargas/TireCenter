#pragma once
#include <iostream>
#include "Article.h"

class DoublyLinkedListOfArticles
{
public:
	void addArticle(unsigned*);
	void deleteArticle(void);
	void displayArticles(void);
	void displayStock(void);
	void updateStock(void);
	void filterArticlesBySize(void);
	void loadFromFile(void);
	void saveToFile(void);
	Article* head;
	Article* tail;
};