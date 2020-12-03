#include "Figures.h"
#include "iostream"
Figures::~Figures() {

}





void Figures::setName(std::string& teampName) {
	name = teampName;
}
void Figures::setDensity(float teampDensity) {
	density = teampDensity;
}
void Figures::getDataFigure() {


	printf(" density:%.2f", density);
	std::cout << " owner:" << name;


}
std::string Figures::getName() {
	return name;
}

std::ostream& operator<<(std::ostream& os, Figures* figure)
{
	figure->getData(os);
	return os;
}
