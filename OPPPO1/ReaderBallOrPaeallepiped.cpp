#include "ReaderBallOrPaeallepiped.h"
#include <string>
#include "ErrorCode.h"
#include "Ball.h"
#include "Parallelepiped.h"
#include "ReaderCube.h"
#include <sstream>
#include <math.h>
#include <regex>
#include "ReaderFiguresWeight.h"
int ReaderBallOrPaeallepiped::stringToInt(const std::string& intString)
{
	std::stringstream stream(intString);
	int intInt;
	stream >> intInt;
	if (stream.fail())
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
	if (stream.fail())
	{
		ErrorCode error;
		error.code = 0;
		error.about = "Critical";
		throw error;
	}
	return floatFloat;
}
ReaderBallOrPaeallepiped::ReaderBallOrPaeallepiped(std::string str)
{
	teamp = str;
}

Figures* ReaderBallOrPaeallepiped::get()
{
	Figures* object;
	std::cmatch result;
	std::regex regularBall(	"ball[\\s]+([+-]?[\\d]+)[\\s]+([+-]?[\\d]+.[\\d]+)[\\s]+(.*)");
	std::regex regularParallelepiped("parallelepiped[\\s]+\\[([+-]?[\\d]+),([+-]?[\\d]+),([+-]?[\\d]+)\\][\\s]+([+-]?[\\d]+.[\\d]+)[\\s]+(.*)");
	if (std::regex_match(teamp.c_str(), result, regularBall)) {
		Figures* figures = ObjBall(result[1].str(), result[2].str(), result[3].str());
		return figures;
	}
	if (std::regex_match(teamp.c_str(), result, regularParallelepiped)) {
		Figures* figures = ObjParalelepiped(result[1].str(), result[2].str(), result[3].str(), result[4].str(), result[5].str());
		return figures;
	}
	ErrorCode error;
	error.code = 1;
	error.about = "ThisIsNotBallOrParallepiped";
	throw error;
}

bool ReaderBallOrPaeallepiped::isOwner(const std::string name) {
	std::cmatch result;
	std::regex regularOwner("([À-ß]|[A-Z])[\\S]+$");
	std::regex regularOwnerSplit("\"([À-ß]|[A-Z])[\\S]+ (.*)\"$");
	if (std::regex_match(name.c_str(), result, regularOwner)|| std::regex_match(name.c_str(), result, regularOwnerSplit))
		return true;
	else
	{
		std::cmatch result;
		std::regex regularOwner("([À-ß]|[A-Z])[\\S]+[\\s]+(.*)");
		std::regex regularOwnerSplit("\"([À-ß]|[A-Z])[\\S]+ (.*)\"[\\s]+(.*)");
		if (std::regex_match(name.c_str(), result, regularOwner) || std::regex_match(name.c_str(), result, regularOwnerSplit)) {
			ErrorCode error;
			error.code = 2;
			error.str = result[3].str();
			error.about = "ToMatchArg";
			throw error;
		}
		return false;

	}

}

Figures* ReaderBallOrPaeallepiped::ObjBall(const std::string& radiusTeamp, const std::string& densityTeamp , const std::string& ownerTeamp) {
	try
	{
		if (isOwner(ownerTeamp)) {
			int radius = stringToInt(radiusTeamp);
			float density = stringToFloat(densityTeamp);
			std::string owner = ownerTeamp;
			Figures* figure = new Ball(radius, density, owner);
			return figure;

		}
		else
		{
			ErrorCode error;
			error.code = 0;
			error.about = "Critical";
		}

	}
	catch (const ErrorCode error)
	{

	}
	

}
Figures* ReaderBallOrPaeallepiped::ObjParalelepiped(const std::string& r1, const std::string& r2, const std::string& r3, const std::string& densityTeamp, const std::string& ownerTeamp) {
	if (isOwner(ownerTeamp)) {
		int r1Int = stringToInt(r1);
		int r2Int = stringToInt(r2);
		int r3Int = stringToInt(r3);
		float density = stringToFloat(densityTeamp);
		std::string owner = ownerTeamp;
		Figures* figures = new Parallelepiped(r1Int, r2Int, r3Int, density, owner);
		return figures;

	}
	else
	{
		ErrorCode error;
		error.code = 0;
		error.about = "Critical";
	}


}



