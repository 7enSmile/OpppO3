#include "ReaderCube.h"
#include <cmath>
#include <regex>
#include <string>
#include "ErrorCode.h"
#include "Cube.h"
#include "ReadOwner.h"
#include "FiguresWeight.h"

ReaderCube::ReaderCube(std::string str)
{
	teamp = str;

}

Figures* ReaderCube::get()
{
	Figures* object;
	std::cmatch result;
	std::regex regularCube("cube[\\s]+([+-]?[\\d]+)[\\s]+([+-]?[\\d]+\.[\\d])[\\s]+(.*)");
	if (std::regex_match(teamp.c_str(), result, regularCube)) {

		Figures* figures = ObjCube(result[1].str(), result[2].str(), result[3].str());
		return figures;

	}
	ErrorCode error;
	error.code = 0;
	error.about = "Critical";
	throw error;
}

Figures* ReaderCube::ObjCube(const std::string& ribTeamp, const std::string& densityTeamp, const std::string& ownerTeamp)
{
	try {
		isOwner(ownerTeamp);
		int radius = stringToInt(ribTeamp);
		float density = stringToFloat(densityTeamp);
		std::string owner = ownerTeamp;
		Figures* figure = new Cube(radius, density, owner);
		return figure;
	}
	catch (const ErrorCode error) {
		if (error.code == 0) {
			throw error;
		}
		if (error.code == 2) {
			int radius = stringToInt(ribTeamp);
			float density = stringToFloat(densityTeamp);
			std::stringstream ss(ownerTeamp);
			std::string owner = readOwner(ss);
			int weight = stringToInt(error.str);
			Figures* figure = new FiguresWeight(new Cube(radius, density, owner), weight);
			return figure;
		}

	}



}
