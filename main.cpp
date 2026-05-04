#include <iostream>
#include "WeatherLang.h"
int main() {
	Memory mem;
	Cpu cpu;
	outPut out;
	WeatherLang lang(&mem, &cpu, &out);
	
	
    lang << "temp x = 5;";
    lang << "temp y = 10;";
    lang << "forecast x;";
    lang << "forecast y;";
    lang << "storm x y;";
    lang << "forecast x;";
    lang << "wind w = 15.5;";
	lang << "forecast w;";
	
	return 0;
}
