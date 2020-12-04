#include "Cube.h"

Cube::~Cube() {

}
Cube::Cube(std::stringstream& stream) {
	float density;
	int weight;
	stream >> rib;
	stream >> density;
	Figures::setDensity(density);

	std::string name = readOwner(stream);
	if (name[0] == '\"') {
		name.erase(0, 1);
		name.erase(name.size() - 1, name.size() - 1);
	}

	Figures::setName(name);

}
void Cube::getData(std::ostream& os) {
	os << std::endl<<"figure:cube " << "rib:" << rib;
	Figures::getDataFigure();
}
std::string Cube::getClass() {
	return "cube";
}

int Cube::getVolume()
{
	return 3 * rib;
}
