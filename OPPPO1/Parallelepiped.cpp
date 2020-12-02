#include "Parallelepiped.h"
#include "sstream"
#include "iostream"
#include <regex>
#include "readOwner.h"
void setRibs(std::string& str, int* mass) {
	std::cmatch result;
	std::regex regular(
		"(\\[)"
		"([+-]?)"
		"([\\d]+)"
		"([,])"
		"([+-]?)"
		"([\\d]+)"
		"([,])"
		"([+-]?)"
		"([\\d]+)"
		"(\\])"


	);
	std::regex_match(str.c_str(), result, regular);
		for (int i = 3; i < 10; i = i + 3) {
			std::istringstream ss(result[i].str());
			int teamp;
			ss >> teamp;
			mass[i / 3 - 1] = teamp;

		}
}
	Parallelepiped::~Parallelepiped() {
		delete[] rib;


	}
	void Parallelepiped::setData(std::stringstream & stream) {
		float density;
		int weight;
		std::string ribs;
		stream >> ribs;
		setRibs(ribs, rib);
		stream >> density;
		Figures::setDensity(density);

		std::string name = readOwner(stream);
		if (name[0] == '\"') {
			name.erase(0, 1);
			name.erase(name.size() - 1, name.size() - 1);
		}

		Figures::setName(name);
		

	}
	void Parallelepiped::getData() {
		std::cout << "figure:parallelepiped " << "r1:" << rib[0] << " r2:" << rib[1] << " r3:" << rib[2];
		Figures::getDataFigure();
	}
	std::string Parallelepiped::getClass() {
		return "parallelepiped";
	}
