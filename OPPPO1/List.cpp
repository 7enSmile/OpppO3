#include "List.h"

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


void List::deleteFigure(const std::string& name) {
	Node* k = top;
	Node* l = top;
	Node* teamp;

	int teampSize = sizeList;
	for (int i = 0; i < sizeList; i++) {

		if (k->figure[0]->getClass() == name) {

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


