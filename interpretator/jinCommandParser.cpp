#include "jinCommandParser.h"

jinCommandParser::jinCommandParser()
{
	right_begin = false;
}

bool isRightSrart(jinFile & file)
{
	if(file.readWord() == "function")
		if(file.readWord() == "void")
			if(file.readWord() == "main")
				if(file.readWord() == "()")
					return true;
				else return false;
			else return false;
		else return false;
	else return false;	
}

void jinCommandParser::startPars(jinFile & file)
{
	if(!file.open())
		errorExit(OPEN_FILE_ERROR);

	if(!isRightSrart(file)) 
		errorExit(MAIN_NOT_FOUND_ERROR);

	while(!file.isEof())
	{
		this->command = file.readWord();
		parsArgs(file, this->command);

		if(this->command == "print") commands.print(arg1);
		else if(this->command == "printl") commands.printl(arg1);
		else if(this->command == "read") commands.read(vars, arg1);
		else if(this->command == "int") vars.newVariable(arg1, arg1_n);
		else if(this->command == "string") vars.newVariable(arg1, arg2);
		else if(this->command == "move") commands.move(vars, arg1, arg2);
		else if(this->command == "//") ;
	}
}

void jinCommandParser::parsArgs(jinFile & file, std::string _command)
{ 

	if(_command == "print" || _command == "printl")
	{
		if(file.readWord() != OPERATION)
		{
			std::string comm = file.getCommand();

			if(containQuotes(comm))
			{
				this->arg1 = newString(changeSpaces(comm)); // "Hello*W" -> Hello W 
			}
			else if(std::regex_match(comm, std::regex("[-+]?\\d+"))) // if number
				this->arg1 = comm;
			else if(vars.isVariable(comm))
			{
				if(vars.isInteger(comm))
					this->arg1 = std::to_string(vars.getIntVar(comm)); // because "print" can show only string
				else if(vars.isString(comm))
					this->arg1 = vars.getStringVar(comm);
			}
		}

		else
		{
			std::string first = file.readWord();

			if(vars.isVariable(first))
			{
				std::string sign = file.readWord();
				std::string second = file.readWord();

				if(vars.isInteger(first))
				{
					operationf.operation(vars, first, second, sign, INT_TYPE);
					this->arg1 = std::to_string(operationf.getIntResult());
				}

				else if(vars.isString(first))
				{
					operationf.operation(vars, first, second, sign, STRING_TYPE);
					this->arg1 = operationf.getStringResult();
				}
			}

			else if(containQuotes(first))
			{
				std::string sign = file.readWord();
				std::string second = newString(changeSpaces(file.readWord()));

				first = changeSpaces(newString(first));

				operationf.operation(first, second, sign);
				this->arg1 = operationf.getStringResult();
			}

			else if(std::regex_match(first, std::regex("[-+]?\\d+")))
			{
				std::string sign = file.readWord();
				int second = file.readNumber();

				operationf.operation(stoi(first), second, sign);
				this->arg1 = std::to_string(operationf.getIntResult());
			}
		}
	}

	else if(_command == "read")
	{
		this->arg1 = file.readWord();
	}

	else if(_command == "string")
	{
		this->arg1 = file.readWord();

		std::string eqop = file.readWord();

		if(eqop == EQUAL)
			this->arg2 = file.readWord(); 
		else errorExit(UNDEFINED_OPERATION_ERROR);
	}

	else if(_command == "int")
	{
		this->arg1 = file.readWord();

		std::string eqop = file.readWord();

		if(eqop == EQUAL)
			this->arg1_n = file.readNumber(); 
		else if(eqop == OPERATION)
		{
			std::string first = file.readWord();

			if(vars.isInteger(first))
			{
				std::string oper = file.readWord();
				std::string second = file.readWord();

				if(vars.isInteger(second))
				{
					operationf.operation(vars, first, second, oper, INT_TYPE);
					this->arg1_n = operationf.getIntResult();
				}

				else 
					errorExit(UNDEFINED_OPERATION_ERROR);
			}

			else if(std::regex_match(first, std::regex("[-+]?\\d+")))
			{
				std::string oper = file.readWord();
				int second = file.readNumber();

				operationf.operation(stoi(first), second, oper);
				this->arg1_n = operationf.getIntResult();
			}

			else 
				errorExit(UNDEFINED_OPERATION_ERROR);
		}
	}

	else if(_command == "move")
	{
		this->arg1 = file.readWord();
		this->arg1.erase(arg1.length() - 1, 1); //erase ','
		
		this->arg2 = file.readWord();
	}

	else if(_command == "//")
	{
		while(_command != ";") _command = file.readWord();
	}
}
