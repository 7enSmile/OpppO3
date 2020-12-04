#include "Figures.h"
#include "iostream"
#include <iomanip>
Figures::~Figures() {

}





void Figures::setName(std::string& teampName) {
	name = teampName;
}
void Figures::setDensity(float teampDensity) {
	density = teampDensity;
}
void Figures::getDataFigure(std::ostream& os) {
	


	os<<" densyty:"<< std::fixed<< std::setprecision(2)<<density;
	os << " owner:" << name;


}
std::string Figures::getName() {
	return name;
}

std::ostream& operator<<(std::ostream& os, Figures* figure)
{
	figure->getData(os);
	return os;
}
