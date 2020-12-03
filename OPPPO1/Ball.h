#pragma once
#include "Figures.h"

class Ball : public Figures
{
private:
	int radius;
public:
	~Ball();
	Ball(std::stringstream& stream);
	void getData();
	std::string getClass();

};

