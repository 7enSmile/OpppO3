#pragma once
#include "Figures.h"
class ReaderCube
{
public:
	ReaderCube(std::string);
	Figures* get();
private:
	std::string teamp;
};

