#include "ReaderBallOrPaeallepiped.h"
#include <string>
#include "CheckFigure.h"
#include "ErrorCode.h"
#include "Ball.h"
#include "Parallelepiped.h"
#include "ReaderCube.h"
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
			object = new Ball(stream);
			
			return object;

		}


		if (type == "parallelepiped") {

			object = new Parallelepiped(stream);
			
			return object;

		}

	}
	catch (const ErrorCode error)
	{
		if (error.code == 1) {

			ReaderCube reder(teamp);
			try
			{
				return reder.get();

			}
			catch (const ErrorCode error)
			{
				throw error;

			}


		}
		else {
			throw error;
		}

	}



}
