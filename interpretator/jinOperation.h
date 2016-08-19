#ifndef _JINOPERATION_H_
#define _JINOPERATION_H_

#include <math.h>

#include "jinVariables.h"

const std::string UNDEFINED_OPERATION_ERROR = "[jin]: undefined operation.\n";

const std::string PLUS = "+";
const std::string MINUS = "-";
const std::string DIVIDE = "/";
const std::string MULTIPLY = "*";
const std::string DEGREE = "^^";

const std::string AND = "&";
const std::string OR = "|";
const std::string XOR = "^";

class jinOperation
{
	std::string result_str;
	int result_int;
public:
	void operation(jinVariables &, std::string, std::string, std::string, const std::string);
	void operation(std::string, std::string, std::string);
	void operation(int, int, std::string);


	int getIntResult();
	std::string getStringResult();
};

#endif
