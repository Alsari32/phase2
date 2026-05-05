#include "WeatherLang.h"


WeatherLang::WeatherLang(Cpu *c,outPut *out)
{
	
	cpu = c;	// cpu now points to main's cpu object
	output = out;// output now points to main's out object
	
}


void WeatherLang::temp(std::string name, int value) 
{
    tempVar* v = new tempVar(name);
    variables.push_back(v);
    cpu->setAccumulator(std::to_string(value));
    cpu->store(v->getMemIndex());
}

void WeatherLang::wind(std::string name, float value) 
{
    WindVar* v = new WindVar(name);
    variables.push_back(v);
    cpu->setAccumulator(std::to_string(value));
    cpu->store(v->getMemIndex());
}

int WeatherLang::findVar(std::string name) {//loops through the vector to find the var 
    for (int x = 0; x < (int)variables.size(); x++) {
        if (variables[x]->getName() == name)
            return x;   // found it, return position
    }
    return -1;  // not found
}

void WeatherLang::storm(std::string dest, std::string src) {
    int di = findVar(dest);
    int si = findVar(src);
    if (variables[di]->getType() == "float") {
        cpu->addFloat(variables[di]->getMemIndex(), variables[si]->getMemIndex());
    } else {
        cpu->add(variables[di]->getMemIndex(), variables[si]->getMemIndex());
    }
    cpu->store(variables[di]->getMemIndex());
}


void WeatherLang::forecast(std::string name) 
{
    int var = findVar(name);
    cpu->load(variables[var]->getMemIndex());
    output->print(name, cpu->getAccumulator());
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


