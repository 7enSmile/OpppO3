#include "CheckFigure.h"
#include <regex>
#include <iostream>
#include "readOwner.h"
#include <sstream>
#include "ErrorCode.h"
bool isInteger(const std::string& str) {
	int i = 0;
	if (str[i] == '-')
		i++;
	for (; i < str.size(); i++)
		if (!isdigit(str[i]))
			return 0;
	return 1;
}


bool isOwner(std::string& str) {
	int i = 0;
	bool split = 0;
	bool checkSpace = 0;

	if (str[i] == '\"') {
		split = 1;
		i++;
	}
	else {
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'À' && str[i] <= 'ß')) {
			i++;
		}
		else
			return 0;

	}
	if (split) {
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'À' && str[i] <= 'ß')) {
			i++;
		}
		else {
			return 0;
		}
	}

	for (; i < str.size(); i++) {
		if (split && str[i] == ' ') {
			checkSpace = 1;
		}
		else {
			if (!split && str[i] == ' ')
				return 0;
		}

	}
	if (split) {
		if (checkSpace && str[str.size() - 1] == '\"')
			return 1;
		else
			return 0;
	}
	else
		return 1;
}

bool isRibs(std::string& str) {
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
	if (std::regex_match(str.c_str(), result, regular)) {
		for (int i = 3; i < 10; i = i + 3) {
			std::istringstream ss(result[i].str());
			int teamp;
			ss >> teamp;
			if (ss.fail())
				return false;
		}
		return true;

	}
	else {
		return false;


	}




}

bool isBall(std::string& figure) {
	std::stringstream stream(figure);
	std::string teamp;
	int integer;
	float density;
	stream >> integer;
	if (stream.fail() || !isInteger(std::to_string(integer)))
	{
		ErrorCode error;
		error.about = "Critical";
		error.code = 0;
		throw error;
	}

	stream >> density;

	if (stream.fail()) {
		ErrorCode error;
		error.about = "Critical";
		error.code = 0;
		throw error;
	}

	std::string owner = readOwner(stream);
	if (!isOwner(owner)) {
		ErrorCode error;
		error.about = "Critical";
		error.code = 0;
		throw error;
	}
	stream.get();
	
	if (stream.eof()) {
		return 1;
	}
	else {
		ErrorCode error;
		error.about = "ToMatchArg";
		error.code = 1;
		throw error;

	}
		

}
bool isParallelepiped(std::string& figure) {
	std::stringstream stream(figure);
	std::string teamp;
	float density;
	stream >> teamp;
	if (!isRibs(teamp))
	{
		ErrorCode error;
		error.about = "Critical";
		error.code = 0;
		throw error;
	}

	stream >> density;

	if (stream.fail()) {
		ErrorCode error;
		error.about = "Critical";
		error.code = 0;
		throw error;
	}
	std::string owner = readOwner(stream);
	if (!isOwner(owner)) {
		ErrorCode error;
		error.about = "Critical";
		error.code = 0;
		throw error;
	}
	stream.get();
	





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



bool checkFigur(std::string  str) {

	std::string function = str;
	std::string type;
	std::string figure;
	std::stringstream stream(str);
	stream >> type;
	while (stream >> str) {
		figure += " " + str;
	}
	figure.erase(0, 1);
	if (type == "ball") {
		return isBall(figure);
	}
	if (type == "parallelepiped") {
		return  isParallelepiped(figure);
	}
	
	
	ErrorCode error;
	error.about = "IsNotBallOrParallepiped";
	error.code = 1;
	throw error;

}
