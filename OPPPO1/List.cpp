#include "List.h"
#include <functional>
List::~List() {
	clear();
}
void List::push(Figures* object) {
	Node* k = new Node;
	k->link = top;
	k->figure[0] = object;
	top = k;
	if (sizeList == 0) {
		last = k;
	}
	last->link = top;
	sizeList++;

}

Node* List::operator[](const int index)
{
	Node* k = top;
	for (int i = 0; i !=index; i++, k = k->link)
	{
		
	}
	return k;
	
}

int List::size()
{
	return sizeList;
}


void List::deleteFigure(std::function<bool(Node)> pred) {
	Node* k = top;
	Node* l = top;
	Node* teamp;

	int teampSize = sizeList;
	for (int i = 0; i < sizeList; i++) {

		if (pred(*k)) {

			if (k == top) {
				teamp = k->link;
				top = teamp;
				delete k->figure[0];
				delete k;

				k = top;
				teampSize--;
			}
			else {
				l->link = k->link;
				delete k->figure[0];
				delete k;
				k = l->link;

				teampSize--;
			}


		}
		else {
			l = k;

			k = k->link;
		}

	}
	sizeList = teampSize;
}
void List::sort(std::function<bool(Node, Node)> pred) {
	Node* k = top;
	Node* l = top;
	for (int i = 0; i < sizeList; i++, k = k->link) {
		for (int j = 0; j < sizeList; j++, l = l->link) {
			if (pred(*k, *l)) {
				std::swap(k->figure[0], l->figure[0]);
			}


		}
	}
}


