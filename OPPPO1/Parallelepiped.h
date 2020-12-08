#pragma once
#include "Figures.h"

class Parallelepiped : public Figures
{
private:
	int* rib = new int[3];
public:
	~Parallelepiped()override;
	Parallelepiped(int,int,int,float,std::string&);
	void getData(std::ostream&);
	int getVolume();
	std::string getClass();
};

