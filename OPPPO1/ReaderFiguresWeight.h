#pragma once
#include <string>
#include "Figures.h"
class ReaderFiguresWeight
{
public:

	ReaderFiguresWeight(std::string,Figures*);
	Figures* get();
private:
	std::string teamp;
	Figures* figure;
};

