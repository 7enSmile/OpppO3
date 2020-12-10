#pragma once
#include "Figures.h"
#include "sstream"
#include "iostream"

class Cube : public Figures
{
public:
	
	Cube(int,float,std::string);
	void getData(std::ostream&);
	std::string getClass();
	int getVolume();
private:
	~Cube();
	int rib;
	
};