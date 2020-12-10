#include "FunctionReader.h"
#include <cmath>
#include <regex>
#include <sstream>
#include <functional>
#include "Node.h"

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
		list->sort([](Node node1, Node node2) {return node1.figure[0]->getName() < node2.figure[0]->getName(); });
	}
}


void FunctionReader::deleteFigure(std::string params)
{
	if(params=="ball")
	list->deleteFigure([](Node node) {return node.figure[0]->getClass() == "ball"; });
	if (params == "cube")
	list->deleteFigure([](Node node) {return node.figure[0]->getClass() == "cube"; });
	if (params == "parallelepiped")
	list->deleteFigure([](Node node) {return node.figure[0]->getClass() == "parallelepiped"; });
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
