#include <iostream>
#include "WeatherLang.h"
int main() {
	Memory mem;
	Cpu cpu(&mem);
	outPut out;
	WeatherLang lang(&cpu, &out);
	
	
    lang << "wind x = 5.5;";
    lang << "wind y = 10.5;";
    lang << "storm x y;";
    lang << "forecast x;";
    lang << "forecast y;";
    lang << "storm x y;";
    lang << "forecast x;";
    lang << "wind w = 15.5;";
	lang << "forecast w;";
	
	return 0;
}
