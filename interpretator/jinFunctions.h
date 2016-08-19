#ifndef _JINFUNCTIONS_H_
#define _JINFUNCTIONS_H_

#include <iostream>
#include <string>

bool containQuotes(std::string str);

std::string newString(std::string old_str);
std::string changeSpaces(std::string str);

void errorExit(std::string error);

#endif
