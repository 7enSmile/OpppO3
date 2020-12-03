#include "ReaderCube.h"
#include "ErrorCode.h"
#include "CheckCube.h"
#include "Figures.h"
#include "Cube.h"
#include "ReaderFiguresWeight.h"

ReaderCube::ReaderCube(std::string str)
{
	teamp = str;
}

Figures* ReaderCube::get()
{
	try
	{
		checkCube(teamp);
		std::string type;
		std::string figure;
		std::stringstream stream(teamp);
		stream >> type;
		Figures *object = new Cube(stream);
		return object;

	}
	catch (const ErrorCode error)
	{
		
		if (error.code == 2) {
			std::string type;
			std::string figure;
			std::stringstream stream(teamp);
			stream >> type;
			Figures* object = new Cube(stream);
			ReaderFiguresWeight a(error.str, object);
			return a.get();

		}
		else {
			throw error;
		}


	}
}
