#include "ReaderBallOrPaeallepiped.h"
#include <string>
#include "CheckFigure.h"
#include "ErrorCode.h"
#include "Ball.h"
#include "Parallelepiped.h"
#include <sstream>

ReaderBallOrPaeallepiped::ReaderBallOrPaeallepiped(std::string str)
{
	teamp = str;
}

Figures* ReaderBallOrPaeallepiped::get()
{
	try
	{
		checkFigur(teamp);
		Figures* object;
		std::string type;
		std::string figure;
		std::stringstream stream(teamp);
		stream >> type;
		if (type == "ball") {
			object = new Ball;
			object->setData(stream);
			return object;
			
		}


		if (type == "parallelepiped") {

			object = new Parallelepiped;
			object->setData(stream);
			return object;
			
		}

	}
	catch (const ErrorCode error)
	{
		throw error;

	}
	

	
}
