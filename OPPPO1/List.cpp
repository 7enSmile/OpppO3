#/*include "List.h"

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
void List::print() {
	Node* k = top;
	for (int i = 0; i < sizeList; i++, k = k->link)
	{
		k->figure[0]->getData();
	}

}

void List::deleteFigure(std::string name) {
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

void List::sort() {
	Node* k = top;
	Node* l = top;
	for (int i = 0; i < sizeList; i++, k = k->link) {
		for (int j = 0; j < sizeList; j++, l = l->link) {
			if (k->figure[0]->getName()[0] < l->figure[0]->getName()[0]) {
				std::swap(k->figure[0], l->figure[0]);
			}
			else
			{
				if (k->figure[0]->getName()[0] == l->figure[0]->getName()[0])
				{
					if (k->figure[0]->getName()[1] < l->figure[0]->getName()[1])
						std::swap(k->figure[0], l->figure[0]);

				}

			}

		}
	}
}*/