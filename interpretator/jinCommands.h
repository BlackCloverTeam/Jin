#ifndef _JINCOMMANDS_H_
#define _JINCOMMANDS_H_

#include <iostream>
#include <string>

#include "jinVariables.h"

class jinCommands
{
public:
	void print(std::string);
	void printl(std::string);

	void read(jinVariables &, std::string);

	void move(jinVariables &, std::string, std::string);
	void move(jinVariables &, int, int);
};

#endif
