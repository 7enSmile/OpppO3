#pragma once
#include "Figures.h"
#include "ReaderBallOrPaeallepiped.h"
class ReaderCube:public ReaderBallOrPaeallepiped
{
public:
	ReaderCube(std::string);
	Figures* get();
private:
	std::string teamp;
	Figures* ObjCube(const std::string&, const std::string&, const std::string&);
};

