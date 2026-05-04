#ifndef CPU_H
#define CPU_H
#include <string>
//lang is the middle man between the cpu and memory
class Cpu
{
	private:
    std::string accumulator; 

	public:
		Cpu();
	    void load(std::string value);  
	    std::string Store();//give memory the accumaltor
	    std::string add(std::string a, std::string b); 
	    std::string subtract(std::string a, std::string b); 
	    std::string multiply(std::string a, std::string b); 
		std::string divide(std::string a, std::string b);
		bool compare(std::string a, std::string b, std::string op);
};		 

		
#endif
