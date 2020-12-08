#include "Ball.h"
#include "sstream"
#include "iostream"

Ball::~Ball() {

}
Ball::Ball(int radiusTeamp, float densityTeamp, std::string& OwnerTeamp)
{
	radius = radiusTeamp;
	Figures::setDensity(densityTeamp);
	Figures::setName(OwnerTeamp);
}

void Ball::getData(std::ostream& os) {
	os << std::endl<<"figure:ball " << "radius:" << radius;
	Figures::getDataFigure(os);
}
std::string Ball::getClass() {
	return "ball";
}

int Ball::getVolume()
{
	return 4 / 3.0 * 3.14 * radius * radius;
}

