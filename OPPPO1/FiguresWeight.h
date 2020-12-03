#pragma once
#include "Decorator.h"
#include "Figures.h"
class FiguresWeight :public Decorator
{
private:
	int weight;
public:
	FiguresWeight(Figures* figure, int teamp);
	void getData();
	
};

