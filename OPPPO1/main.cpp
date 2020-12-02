#include <fstream>
#include <string>
#include <sstream>
#include "Figures.h"
#include "Parallelepiped.h"
#include "List.h"
#include "Ball.h"
#include "ErrorCode.h"
#include "ReaderBallOrPaeallepiped.h"



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
			obj->getData();

		}
		catch (const ErrorCode)
		{

		}
		

	}
	
	
	
	
	
	return 1;

	
}

