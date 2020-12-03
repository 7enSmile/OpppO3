#pragma once
#include "string"

class Figures {
private:
	float density;
	std::string name;
public:
	virtual ~Figures();
	virtual void getData() = 0;
	virtual std::string getClass() = 0;
	
	void setName(std::string& teampName);
	void setDensity(float teampDensity);
	void getDataFigure();
	std::string getName();
};

