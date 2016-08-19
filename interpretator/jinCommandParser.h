#ifndef _JINCOMMANDPARSER_H_
#define _JINCOMMANDPARSER_H_

#include <stdlib.h>

#include "jinFile.h"
#include "jinCommands.h"
#include "jinFunctions.h"
#include "jinVariables.h"
#include "jinOperation.h"

const std::string MAIN_NOT_FOUND_ERROR = "[jin]: function 'main' not found.\n";
const std::string OPEN_FILE_ERROR = "[jin]: can not open file.\n";

const std::string OPERATION = "->";
const std::string EQUAL = "=";

class jinCommandParser
{
private:
	std::string command;
	std::string arg1, arg2;
	int arg1_n, arg2_n;
	std::string operation;

	bool right_begin;

	//jinFile file;

	jinVariables vars;
	jinCommands commands;
	jinOperation operationf;
public:
	jinCommandParser();
	//jinCommandParser(jinFile &);

	void startPars(jinFile &);
	void parsArgs(jinFile &, std::string);

	bool isRightStart(jinFile &);
	//void errorExit(std::string);
};

#endif
