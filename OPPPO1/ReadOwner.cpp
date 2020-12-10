#include "ReadOwner.h"

std::string readOwner(std::stringstream& stream)
{
	std::string str;
	char c;
	int err = 0;
	
	if (stream.peek() != '"') {
		stream >> str;
		return str;
	}
	stream.get(c);
	str += c;
	while (1) {

		stream.get(c);
		if (c == '"' || err == 50) {
			str += c;
			break;
		}
		str += c;
		err++;
	}
	return str;
}
