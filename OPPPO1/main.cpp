#include <fstream>
#include <sstream>
#include <iostream>
#include "List.h"
#include "ErrorCode.h"
#include "ReaderBallOrPaeallepiped.h"
#include "Ball.h"
#include "FunctionReader.h"



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
			list->push(obj);
			
			

		}
		catch (const ErrorCode)
		{
			FunctionReader a(str, list);
			a.startFunction();

		}


	}
	
	
	
	
	for (int i = 0; i < list->size(); i++) {
		std::cout << (*list)[i]->figure[0];
	}
	std::cout << std::endl<<list->size();
	
	




	delete list;



	return 0;


}

