#pragma once
#include "Figures.h"
#include "sstream"
#include "iostream"
#include "readOwner.h"
class Cube : public Figures
{
public:
	int rib;
private:
	~Cube();
	void setData(std::stringstream& stream);
	void getData();
	std::string getClass();
};