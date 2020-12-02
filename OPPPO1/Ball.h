#pragma once
#include "Figures.h"

class Ball : public Figures
{
private:
	int radius;
public:
	~Ball();
	void setData(std::stringstream& stream);
	void getData();
	std::string getClass();

};

