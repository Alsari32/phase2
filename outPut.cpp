#include "outPut.h"



void outPut::display(std::string message) {
    std::cout << message << "\n";
}

void outPut::print(std::string name,std::string value)
{
	std::cout << "forecast" << name << " = " << value << "\n";
}
