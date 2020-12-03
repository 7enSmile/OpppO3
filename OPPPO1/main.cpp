#include <fstream>
#include <sstream>
#include <iostream>
#include "List.h"
#include "ErrorCode.h"
#include "ReaderBallOrPaeallepiped.h"
#include "Ball.h"



int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	setlocale(LC_NUMERIC, "C");
	std::ifstream in(argv[1]);
	std::string str;

	List* list = new List();


	while (!in.eof()) {
		std::getline(in, str);
		ReaderBallOrPaeallepiped reader(str);
		try
		{
			Figures* obj = reader.get();
			std::cout << obj->getClass();

		}
		catch (const ErrorCode)
		{

		}


	}





	return 1;


}

