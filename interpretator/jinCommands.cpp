#include "jinCommands.h"

void jinCommands::print(std::string line)
{
	std::cout << line;
}

void jinCommands::printl(std::string line)
{
	std::cout << line << std::endl;
}

void jinCommands::read(jinVariables & vars, std::string name)
{
	if(vars.isVariable(name))
	{
		if(vars.isInteger(name))
		{
			vars.readIntFromKeyboard(name);
		}

		else if(vars.isString(name))
		{
			vars.readStringFromKeyboard(name);
		}
	}
}

void jinCommands::move(jinVariables & vars, std::string input, std::string output)
{
	if(vars.isInteger(input) && vars.isInteger(output))
		vars.setIntValue(input, vars.getIntVar(output)); 
	else if(vars.isString(input) && vars.isString(output))
		vars.setStringValue(input, vars.getStringVar(output)); 
}

