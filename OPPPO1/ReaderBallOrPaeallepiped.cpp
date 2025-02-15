#include "ReaderBallOrPaeallepiped.h"
#include <string>
#include "ErrorCode.h"
#include "Ball.h"
#include "Parallelepiped.h"
#include "ReaderCube.h"
#include <sstream>
#include <math.h>
#include <regex>
#include "FiguresWeight.h"
#include "ReadOwner.h"

#include <sstream>
int ReaderBallOrPaeallepiped::stringToInt(const std::string& intString)
{
	std::stringstream stream(intString);
	int intInt;
	stream >> intInt;
	if (stream.fail()||!stream.eof())
	{
		ErrorCode error;
		error.code = 0;
		error.about = "Critical";
		throw error;
	}
	return intInt;
}
float ReaderBallOrPaeallepiped::stringToFloat(const std::string floatString)
{
	std::stringstream stream(floatString);
	float floatFloat;
	stream >> floatFloat;
	if (stream.fail() || !stream.eof())
	{
		ErrorCode error;
		error.code = 0;
		error.about = "Critical";
		throw error;
	}
	return floatFloat;
}
ReaderBallOrPaeallepiped::ReaderBallOrPaeallepiped()
{
}
ReaderBallOrPaeallepiped::ReaderBallOrPaeallepiped(std::string str)
{
	teamp = str;
}

Figures* ReaderBallOrPaeallepiped::get()
{
	Figures* object;
	std::cmatch result;
	std::regex regularBall("ball[\\s]+([+-]?[\\d]+)[\\s]+([+-]?[\\d]+\\.[\\d]+)[\\s]+(.*)");
	std::regex regularParallelepiped("parallelepiped[\\s]+\\[([+-]?[\\d]+),([+-]?[\\d]+),([+-]?[\\d]+)\\][\\s]+([+-]?[\\d]+\\.[\\d]+)[\\s]+(.*)");
	if (std::regex_match(teamp.c_str(), result, regularBall)) {
		Figures* figures = ObjBall(result[1].str(), result[2].str(), result[3].str());
		return figures;
	}
	if (std::regex_match(teamp.c_str(), result, regularParallelepiped)) {
		Figures* figures = ObjParalelepiped(result[1].str(), result[2].str(), result[3].str(), result[4].str(), result[5].str());
		return figures;
	}
	ReaderCube a(teamp);
	try
	{
		return a.get();
	}
	catch (const ErrorCode error)
	{
		throw error;
	}
}

void ReaderBallOrPaeallepiped::isOwner(const std::string name) {
	std::cmatch result;
	std::regex regularOwner("([�-�]|[A-Z])[\\S]+$");
	std::regex regularOwnerSplit("\"([�-�]|[A-Z])[\\S]+ (.*)\"$");
	if (std::regex_match(name.c_str(), result, regularOwner) || std::regex_match(name.c_str(), result, regularOwnerSplit))
	{
	}
	else
	{
		std::cmatch result;
		std::regex regularOwner("([�-�]|[A-Z])[\\S]+[\\s]+(.*)");
		std::regex regularOwnerSplit("\"([�-�]|[A-Z])[\\S]+ .*\"[\\s]+(.*)");
		if (std::regex_match(name.c_str(), result, regularOwner) || std::regex_match(name.c_str(), result, regularOwnerSplit)) {
			ErrorCode error;
			error.code = 2;
			error.str = result[2].str();
			error.about = "ToMatchArg";
			throw error;
		}
		ErrorCode error;
		error.code = 0;
		error.about = "Critical";
		throw error;

	}
}

Figures* ReaderBallOrPaeallepiped::ObjBall(const std::string& radiusTeamp, const std::string& densityTeamp, const std::string& ownerTeamp) {
	try {
		isOwner(ownerTeamp);
		int radius = stringToInt(radiusTeamp);
		float density = stringToFloat(densityTeamp);
		std::string owner = ownerTeamp;
		Figures* figure = new Ball(radius, density, owner);
		return figure;
	}
	catch (const ErrorCode error) {
		if (error.code == 0) {
			throw error;
		}
		if (error.code == 2) {
			int radius = stringToInt(radiusTeamp);
			float density = stringToFloat(densityTeamp);
			std::stringstream ss(ownerTeamp);
			std::string owner = readOwner(ss);
			int weight = stringToInt(error.str);
			Figures* figure = new FiguresWeight(new Ball(radius, density, owner), weight);
			return figure;
		}

	}




}
Figures* ReaderBallOrPaeallepiped::ObjParalelepiped(const std::string& r1, const std::string& r2, const std::string& r3, const std::string& densityTeamp, const std::string& ownerTeamp) {
	try {
		isOwner(ownerTeamp);
		int r1Int = stringToInt(r1);
		int r2Int = stringToInt(r2);
		int r3Int = stringToInt(r3);
		float density = stringToFloat(densityTeamp);
		std::string owner = ownerTeamp;
		Figures* figures = new Parallelepiped(r1Int, r2Int, r3Int, density, owner);
		return figures;
	}
	catch (const ErrorCode error) {
		if (error.code == 0) {
			throw error;
		}
		if (error.code == 2) {
			int r1Int = stringToInt(r1);
			int r2Int = stringToInt(r2);
			int r3Int = stringToInt(r3);
			float density = stringToFloat(densityTeamp);
			std::stringstream ss(ownerTeamp);
			std::string owner = readOwner(ss);
			int weight = stringToInt(error.str);
			Figures* figure = new FiguresWeight(new Parallelepiped(r1Int, r2Int, r3Int, density, owner), weight);
			return figure;
		}

	}




}



