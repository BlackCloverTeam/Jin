#include "jinVariables.h"
#include "jinFunctions.h"

void jinVariables::newVariable(std::string name, std::string value)
{
	if(containQuotes(value))
	{
		str_vars[name] = newString(changeSpaces(value));
	}
	else errorExit(UNDEFINED_VARIABLE_VALUE_ERROR);

	types[name] = STRING_TYPE;
	is_vars[name] = true;
}

void jinVariables::newVariable(std::string name, int value)
{
	int_vars[name] = value;
	types[name] = INT_TYPE;
	is_vars[name] = true;
}

bool jinVariables::isVariable(std::string name)
{
	return is_vars[name];
}

bool jinVariables::isInteger(std::string name)
{
	return types[name] == INT_TYPE;
}

bool jinVariables::isString(std::string name)
{
	return types[name] == STRING_TYPE;
}

int jinVariables::getIntVar(std::string name)
{
	return int_vars[name];
}

std::string jinVariables::getStringVar(std::string name)
{
	return str_vars[name];
}

void jinVariables::setStringValue(std::string name, std::string value)
{
	if(types[name] == STRING_TYPE) str_vars[name] = value;
}

void jinVariables::setIntValue(std::string name, int value)
{
	if(types[name] == INT_TYPE) int_vars[name] = value;
}

void jinVariables::readIntFromKeyboard(std::string name)
{
	if(isVariable(name))
		std::cin >> int_vars[name];
	else errorExit(VAR_NOT_FOUND_ERROR);
}

void jinVariables::readStringFromKeyboard(std::string name)
{
	if(isVariable(name))
		std::cin >> str_vars[name];
	else errorExit(VAR_NOT_FOUND_ERROR);
}