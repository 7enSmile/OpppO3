#include "FiguresWeight.h"
#include <iostream>
FiguresWeight::FiguresWeight(Figures* figure, int teamp):Decorator(figure)
{
	weight = teamp;
}

void FiguresWeight::getData(std::ostream& os)
{
	Decorator::getData(os);
	os << " weight:" << weight;
}

std::string FiguresWeight::getCalss()
{
	return Decorator::getClass();
}

