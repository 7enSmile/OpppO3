#include "ReaderBallOrPaeallepiped.h"
#include <string>
#include "CheckFigure.h"
#include "ErrorCode.h"
#include "Ball.h"
#include "Parallelepiped.h"
#include "ReaderCube.h"
#include <sstream>
#include "ReaderFiguresWeight.h"
ReaderBallOrPaeallepiped::ReaderBallOrPaeallepiped(std::string str)
{
	teamp = str;
}

Figures* ReaderBallOrPaeallepiped::get()
{
	Figures* object;
	try
	{
		checkFigur(teamp);
		object = createObj(teamp);
		return object;
	}
	catch (const ErrorCode error)
	{
		if (error.code == 1) {

			ReaderCube reder(teamp);

			return reder.get();





		}
		else {


			if (error.code == 2) {
				object = createObj(teamp);



				ReaderFiguresWeight a(error.str, object);
				return a.get();




			}
			



		}

	}

}




Figures* ReaderBallOrPaeallepiped::createObj(std::string teamp) {
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

