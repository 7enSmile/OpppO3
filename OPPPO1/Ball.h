#pragma once
#include "Figures.h"
#include <fstream>

class Ball : public Figures
{
private:
	int radius;
public:
	~Ball();
	Ball(int,float,std::string&);
	void getData(std::ostream&);
	std::string getClass();
	int getVolume();

};

