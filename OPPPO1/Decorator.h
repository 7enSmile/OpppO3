#pragma once
#include "Figures.h"
class Decorator :public Figures
{
private:
	Figures* figure;
public:
	Decorator(Figures* f);
	void getData(std::ostream&);
	std::string getClass();
	int getVolume();
};

