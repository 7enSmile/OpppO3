#include "FunctionReader.h"
#include <cmath>
#include <regex>
#include <sstream>

FunctionReader::FunctionReader(std::string strTeamp, List* listTeamp)
{
	str = strTeamp;
	list = listTeamp;
}

void FunctionReader::startFunction()
{
	checkFunction();
}

void FunctionReader::sort(std::string params)
{
	if (params == "name") {
		for (int i = 0; i < list->size(); i++) {
			for (int j = 0; j < list->size(); j++) {
				if ((*list)[i]->figure[0]->getName() < (*list)[j]->figure[0]->getName()) {
					std::swap((*list)[i]->figure[0], (*list)[j]->figure[0]);

				}

			}
		}
	}
}

void FunctionReader::deleteFigure(std::string params)
{
	list->deleteFigure(params);
}

bool FunctionReader::checkFunction()
{
	std::cmatch result;
	std::regex regular(
		"function ((delete (?:ball|parallelepiped|cube))|(sort name))$"


	);
	if (std::regex_match(str.c_str(), result, regular)) {

		std::istringstream ss(result[1].str());
		std::string function;
		std::string params;
		ss >> function;
		ss >> params;
		if (function == "sort") {
			sort(params);
		}
		if (function == "delete") {
			deleteFigure(params);
		}


	}
	else {
		return false;
	}
}
