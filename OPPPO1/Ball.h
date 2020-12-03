#pragma once
#include "Figures.h"
#include <fstream>

class Ball : public Figures
{
private:
	int radius;
public:
	~Ball();
	Ball(std::stringstream& stream);
	void getData(std::ostream&);
	std::string getClass();

};

