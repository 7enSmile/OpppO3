#pragma once
#include "string"
#include "Figures.h"
#include "Node.h"
#include <functional>
class List
{
private:
	Node* top, * last;
	int sizeList = 0;
	void clear() {

		Node* k = top;
		Node* teamp;
		for (int i = 0; i < sizeList; i++)
		{
			teamp = k;
			k = k->link;

			delete teamp->figure[0];

			delete teamp;
		}


	}
public:
	~List();
	void push(Figures* object);
	Node* operator [](const int index);
	int size();
	void deleteFigure(std::function<bool(Node)> pred);
	void sort(std::function<bool(Node, Node)> pred);
	
};

