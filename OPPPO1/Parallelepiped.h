#pragma once
#include "Figures.h"

class Parallelepiped : public Figures
{
private:
	int* rib = new int[3];
private:
	~Parallelepiped()override;
	void setData(std::stringstream& stream);
	void getData();
	std::string getClass();
};

