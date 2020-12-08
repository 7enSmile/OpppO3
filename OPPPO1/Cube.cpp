#include "Cube.h"

Cube::~Cube() {

}
Cube::Cube(std::stringstream& stream) {
	
}
void Cube::getData(std::ostream& os) {
	os << std::endl<<"figure:cube " << "rib:" << rib;
	Figures::getDataFigure(os);
}
std::string Cube::getClass() {
	return "cube";
}

int Cube::getVolume()
{
	return 3 * rib;
}
