#include "FiguresWeight.h"
#include <iostream>
FiguresWeight::FiguresWeight(Figures* figure, int teamp):Decorator(figure)
{
	weight = teamp;
}

void FiguresWeight::getData()
{
	Decorator::getData();
	std::cout << " weight:" << weight;
}

