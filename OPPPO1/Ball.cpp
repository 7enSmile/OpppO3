#include "Ball.h"
#include "sstream"
#include "iostream"
#include "readOwner.h"
Ball::~Ball() {

}
Ball::Ball(std::stringstream& stream) {
	float density;
	int weight;
	stream >> radius;
	stream >> density;
	Figures::setDensity(density);
	std::string name = readOwner(stream);
	if (name[0] == '\"') {
		name.erase(0, 1);
		name.erase(name.size() - 1, name.size() - 1);
	}

	Figures::setName(name);




}
void Ball::getData() {
	std::cout << std::endl<<"figure:ball " << "radius:" << radius;
	Figures::getDataFigure();
}
std::string Ball::getClass() {
	return "ball";
}

