#pragma once
#include "string"
#include <ostream>

class Figures {
private:
	float density;
	std::string name;
public:
	virtual ~Figures();
	virtual void getData(std::ostream&) = 0;
	friend std::ostream& operator<<(std::ostream& os, Figures* figure);
	virtual std::string getClass() = 0;
	virtual int getVolume() = 0;
	void setName(std::string& teampName);
	void setDensity(float teampDensity);
	void getDataFigure();
	std::string getName();
};

