#pragma once

#include <string>
#include "Figures.h"
class ReaderBallOrPaeallepiped
{
private:
	std::string teamp;
public:
	Figures* createObj(std::string teamp);
	ReaderBallOrPaeallepiped(std::string);
	Figures* get();


};

