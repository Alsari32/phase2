#include "WeatherLang.h"


WeatherLang::WeatherLang(Memory *mem,Cpu *c,outPut *out)
{
	memory = mem;// memory now points to main's mem object
	cpu = c;	// cpu now points to main's cpu object
	output = out;// output now points to main's out object
	
}


void WeatherLang::temp(std::string name, int value)
{
	tempVar* v = new tempVar(name);
	variables.push_back(v);
	memory->store(v->getMemIndex(), std::to_string(value));//sends the index and converts the value into string
}

void WeatherLang::wind(std::string name, float value)
{
	WindVar* v = new WindVar(name);
	variables.push_back(v);
	memory->store(v->getMemIndex(), std::to_string(value));//sends the index and converts the value into string
}

int WeatherLang::findVar(std::string name) {//loops through the vector to find the var 
    for (int x = 0; x < (int)variables.size(); x++) {
        if (variables[x]->getName() == name)
            return x;   // found it, return position
    }
    return -1;  // not found
}

void WeatherLang::storm(std::string dest, std::string src)
{
	int di = findVar(dest);//di is the position of dest in the vector
	int si = findVar(src);
	
	std::string destValue = memory->load(variables[di]->getMemIndex());  // memory->load gives us the value
    std::string srcValue  = memory->load(variables[si]->getMemIndex());

	cpu->add(destValue,srcValue);//adds two var
	std::string result = cpu->Store();  
	memory->store(variables[di]->getMemIndex(), result);// send result back to memory
}


void WeatherLang::forecast(std::string name)
{
	int var = findVar(name);
	std::string value = memory->load(variables[var]->getMemIndex());
	output ->print(name,value);
}

void WeatherLang::run(std::string line) {
    // step 1 - strip the semicolon
    if (!line.empty() && line.back() == ';')
        line.pop_back();

    // step 2 - read word by word
    std::istringstream ss(line);
    std::string keyword;
    ss >> keyword;

    // step 3 - check keyword and call right function
    if (keyword == "temp") {
    	try{
	        std::string name, eq;
	        int value;
	        ss >> name >> eq >> value;   // reads temp "x" "=" 5
	        temp(name, value);
    	} catch(std::exception& e){
    		std::cout << "WeatherLang error: invalid value for temp\n";
		}
	}
        
    else if (keyword == "wind") {
        try{
	        std::string name, eq;
	        float value;
	        ss >> name >> eq >> value;   // reads wind "x" "=" 5
	        wind(name, value);
    	} catch(std::exception& e){
    		std::cout << "WeatherLang error: invalid value for wind\n";
		}
	}
    else if (keyword == "storm") {
    	try{
		
	        std::string dest, src;
	        ss >> dest >> src;           // reads "x" "y"
	        storm(dest, src);
    	} catch (std::exception& e){
    		 std::cout << "WeatherLang error: unknown variable in storm\n";
		}
    	
    		
		
	}
    else if (keyword == "forecast") {
    	try{
		
	        std::string name;
	        ss >> name;                  // reads "x"
	        forecast(name);
    	} catch(std::exception& e){
    		std::cout << "WeatherLang error: unknown variable in forecast\n";
		}
	}
	
    else {
        std::cout << "error: unknown keyword '" << keyword << "'\n";
    }
    
    
    
}

WeatherLang& WeatherLang::operator<<(std::string line) {
    run(line);
    return *this;
}


