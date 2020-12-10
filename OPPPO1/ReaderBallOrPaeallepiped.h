#pragma once

#include <string>
#include <math.h>
#include "Figures.h"
using namespace std;
class ReaderBallOrPaeallepiped
{
private:
	std::string teamp;
	
	Figures* ObjBall(const std::string&, const std::string&, const std::string&);
	Figures* ObjParalelepiped(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&);
	
public:
	ReaderBallOrPaeallepiped();
	ReaderBallOrPaeallepiped(std::string);
	
	Figures* get();
protected:
	int stringToInt(const std::string& intString);
	float stringToFloat(const std::string floatString);
	void isOwner(const std::string name);
	


};

