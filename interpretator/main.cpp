#include <iostream>

#include "jinFile.h"
#include "jinCommandParser.h"

int main()
{
	jinFile file("asdf.jin");

	jinCommandParser com;

	com.startPars(file);
	
}
