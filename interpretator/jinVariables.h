#ifndef _JINVARIABLES_H_
#define _JINVARIABLES_H_

#include <string>
#include <vector>
#include <map>

#include "jinFunctions.h"

const std::string STRING_TYPE = "string";
const std::string INT_TYPE = "int";

const std::string UNDEFINED_VARIABLE_VALUE_ERROR = "[jin]: undefined value.\n";
const std::string VAR_NOT_FOUND_ERROR = "[jin]: variable not found.\n";

class jinVariables
{
private:
	std::map<std::string, int> int_vars;
	std::map<std::string, std::string> str_vars;

	std::map<std::string, std::string> types;

	std::map<std::string, bool> is_vars;
public:
	void newVariable(std::string, std::string);
	void newVariable(std::string, int);

	bool isVariable(std::string);
	bool isInteger(std::string);
	bool isString(std::string);

	int getIntVar(std::string);
	std::string getStringVar(std::string); 

	void setIntValue(std::string, int);
	void setStringValue(std::string, std::string);

	void readIntFromKeyboard(std::string);
	void readStringFromKeyboard(std::string);
};

#endif
