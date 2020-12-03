#pragma once
#include "Figures.h"
#include "sstream"
#include "iostream"
#include "readOwner.h"
class Cube : public Figures
{
public:
	int rib;
	Cube(std::stringstream& stream);
private:
	~Cube();
	
	void getData(std::ostream&);
	std::string getClass();
};