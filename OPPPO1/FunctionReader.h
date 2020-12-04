#pragma once
#include "List.h"
#include <string>
class FunctionReader
{
	


public:
	FunctionReader(std::string,List*);
	void startFunction();
private:
	void sort(std::string);
	void deleteFigure(std::string);
	bool checkFunction();
	std::string str;
	List* list;

};

