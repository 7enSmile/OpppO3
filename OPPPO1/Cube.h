#pragma once
#include "Figures.h"
#include "sstream"
#include "iostream"

class Cube : public Figures
{
public:
	
	Cube(std::stringstream& stream);
	void getData(std::ostream&);
	std::string getClass();
	int getVolume();
private:
	~Cube();
	int rib;
	
};