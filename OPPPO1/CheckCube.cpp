#include "CheckCube.h"
#include "ErrorCode.h"
#include <sstream>
#include "CheckFigure.h"
#include "readOwner.h"

bool isCube(std::string& figure)
{
	std::stringstream stream(figure);
	std::string teamp;
	int integer;
	float density;
	stream >> integer;
	if (stream.fail() || !isInteger(std::to_string(integer)))
	{
		ErrorCode error;
		error.code = 0;
		error.about = "Critical";
		throw error;
	}

	stream >> density;

	if (stream.fail()) {
		ErrorCode error;
		error.code = 0;
		error.about = "Critical";
		throw error;
	}

	std::string owner = readOwner(stream);
	if (!isOwner(owner)) {
		ErrorCode error;
		error.code = 0;
		error.about = "Critical";
		throw error;
	}
	

	if (stream.eof()) {
		return 1;
	}
	else {
		ErrorCode error;
		error.about = "ToMatchArg";
		error.code = 2;
		throw error;

	}
		
}

bool checkCube(std::string str)
{
	std::string function = str;
	std::string type;
	std::string figure;
	std::stringstream stream(str);
	stream >> type;
	while (stream >> str) {
		figure += " " + str;
	}
	figure.erase(0, 1);
	if (type == "cube") {
		return isCube(figure);
	}
	ErrorCode error;
	error.code = 1;
	error.about = "isNotCube";
	throw error;
}
