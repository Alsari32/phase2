#ifndef WEATHERLANG_H
#define WEATHERLANG_H

#include "Cpu.h"
#include "Memory.h"
#include "tempVar.h"
#include "Variable.h"
#include "WindVar.h"
#include "outPut.h"
#include "inPut.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>


class WeatherLang
{
	private:
		Cpu *cpu;
		outPut *output;
		inPut *input;
		std::vector<Variable*> variables;  // holds BOTH tempVar and WindVar
		int findVar(std::string name);//find variable box and get the index  to output
	public:
		WeatherLang(Cpu* cpu, outPut* output);
		
		// WeatherLang commands
		void temp(std::string name, int value);
		void wind(std::string name, float value);
		void storm(std::string dest, std::string src);//takes two var and addes them
		void forecast(std::string name);
		
		void run(std::string line); // parses the line and calls the right function
		WeatherLang& operator<<(std::string line);//lets main use << to run WeatherLang code
		
		
};

#endif
