#include "jinFunctions.h"

bool containQuotes(std::string str)
{
	if (str[0] == '\"' && str[str.length() - 1] == '\"')
		return true;
	else 
		return false;
}

std::string newString(std::string old_str)
{
	std::string temp_str = "";

	for (int count(1); count != (old_str.length() - 1); count++)
		temp_str += old_str[count];

	return temp_str;
}

void errorExit(std::string error)
{
	std::cout << error << std::endl;

	std::exit(0);
}

std::string changeSpaces(std::string str)
{
	for(auto & i : str)
	{
		if(i == '$') i = ' ';
	}

	return str;
}