#include "Parallelepiped.h"
#include "sstream"
#include "iostream"
#include <regex>

#include "Parallelepiped.h"

Parallelepiped::~Parallelepiped() {
	delete[] rib;


}
Parallelepiped::Parallelepiped(int r1, int r2, int r3, float density, std::string& owner)
{
	rib[0] = r1;
	rib[1] = r2;
	rib[2] = r3;
	Figures::setDensity(density);
	Figures::setName(owner);

}

void Parallelepiped::getData(std::ostream& os) {
	os<< std::endl<< "figure:parallelepiped " << "r1:" << rib[0] << " r2:" << rib[1] << " r3:" << rib[2];
	Figures::getDataFigure(os);
}
int Parallelepiped::getVolume()
{
	return rib[0] * rib[1] * rib[2];
}
std::string Parallelepiped::getClass() {
	return "parallelepiped";
}
