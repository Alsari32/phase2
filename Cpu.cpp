#include "Cpu.h"


Cpu::Cpu() {
    accumulator = "0";
}
//================= Loading function loads a value from memory into a register/Accumulator
void Cpu::load(std::string value) {
    accumulator = value;
}

//=====================Stores value from a register/accumulator into memory
std::string Cpu::Store()
{
	return accumulator;
}


//=======================add two values and stores the result into register/accumulator
std::string Cpu::add(std::string a, std::string b) {
    int result = std::stoi(a) + std::stoi(b);
    accumulator = std::to_string(result);
    return accumulator;
    
}

std::string Cpu::subtract(std::string a, std::string b) {
    int result = std::stoi(a) - std::stoi(b);
    accumulator = std::to_string(result);
    return accumulator;
    
}

std::string Cpu::multiply(std::string a, std::string b) {
    int result = std::stoi(a) * std::stoi(b);
    accumulator = std::to_string(result);
    return accumulator;
    
}

std::string Cpu::divide(std::string a, std::string b) {
    int result = std::stoi(a) / std::stoi(b);
    accumulator = std::to_string(result);
    return accumulator;
    
}

bool Cpu::compare(std::string a, std::string b, std::string op)
{
	int x = std::stoi(a);
    int y = std::stoi(b);
    if (op == ">")  return x > y;
    if (op == "<")  return x < y;
    if (op == "==") return x == y;
    return false;
}








