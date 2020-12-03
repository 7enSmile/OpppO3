#include "ReaderFiguresWeight.h"
#include "ErrorCode.h"
#include "CheckWeight.h"
#include <sstream>
#include "FiguresWeight.h"
ReaderFiguresWeight::ReaderFiguresWeight(std::string str,Figures* teampFigure)
{
	teamp = str;
	teamp.erase(teamp.size() - 1, teamp.size());
	figure = teampFigure;
}

Figures* ReaderFiguresWeight::get()
{
	
	if (checkWeight(teamp)) {
		int weight;
		std::stringstream ss(teamp);
		ss >> weight;
		Figures* figureWeighr = new FiguresWeight(figure, weight);
		return figureWeighr;


	}
	else
	{
		ErrorCode error;
		error.code = 0;
		error.about = "Critical";
		throw error;
	}


	
}
