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

