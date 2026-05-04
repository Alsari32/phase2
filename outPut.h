#ifndef OUTPUT_H
#define OUTPUT_H
#include "IO.h"
#include <iostream>
class outPut : public IO
{
	public:
		void display(std::string message);
		void print(std::string name,std::string value);
	
};

#endif
