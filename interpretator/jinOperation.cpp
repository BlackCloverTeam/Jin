#include "jinOperation.h"

void jinOperation::operation(jinVariables & vars, std::string first, std::string second, std::string operation, const std::string type)
{
	if(type == INT_TYPE)
	{
		if(operation == PLUS) result_int = vars.getIntVar(first) + vars.getIntVar(second);
		else if(operation == MINUS) result_int = vars.getIntVar(first) - vars.getIntVar(second);
		else if(operation == DIVIDE) result_int = vars.getIntVar(first) / vars.getIntVar(second);
		else if(operation == MULTIPLY) result_int = vars.getIntVar(first) * vars.getIntVar(second);
		else if(operation == DEGREE) result_int = pow(vars.getIntVar(first), vars.getIntVar(second));

		else if(operation == AND) result_int = vars.getIntVar(first) & vars.getIntVar(second);
		else if(operation == OR) result_int = vars.getIntVar(first) | vars.getIntVar(second);
		else if(operation == XOR) result_int = vars.getIntVar(first) ^ vars.getIntVar(second);

		else errorExit(UNDEFINED_OPERATION_ERROR);

	}

	else if(type == STRING_TYPE)
	{
		if(operation == PLUS) result_str = vars.getStringVar(first) + vars.getStringVar(second);
		else errorExit(UNDEFINED_OPERATION_ERROR);

	}
}

void jinOperation::operation(int first, int second, std::string operation)
{
	if(operation == PLUS) result_int = first + second;
	else if(operation == MINUS) result_int = first - second;
	else if(operation == DIVIDE) result_int = first / second;
	else if(operation == MULTIPLY) result_int = first * second;
	else if(operation == DEGREE) result_int = pow(first, second);

	else if(operation == AND) result_int = first & second;
	else if(operation == OR) result_int = first | second;
	else if(operation == XOR) result_int = first ^ second;

	else errorExit(UNDEFINED_OPERATION_ERROR);
}

void jinOperation::operation(std::string first, std::string second, std::string operation)
{
	if(operation == PLUS) result_str = first + second;
	else errorExit(UNDEFINED_OPERATION_ERROR);
}

int jinOperation::getIntResult()
{
	return result_int;
}

std::string jinOperation::getStringResult()
{
	return result_str;
}