#pragma once
#include "Figures.h"

class Parallelepiped : public Figures
{
private:
	int* rib = new int[3];
public:
	~Parallelepiped()override;
	Parallelepiped(std::stringstream& stream);
	void getData(std::ostream&);
	std::string getClass();
};

