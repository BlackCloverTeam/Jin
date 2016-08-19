#ifndef _JINFILE_H_
#define _JINFILE_H_

#include <fstream>
#include <string>
#include <regex>

/*

class jinFile

Contain functions which works with file 

*/

class jinFile
{
private:
	std::string filename;
	std::ifstream file_reader;
	std::string command_str;
	int number;
public:
	jinFile();
	jinFile(std::string);

	bool isRightName();
	bool isEof();
	bool open();

	void setFilename(std::string);

	std::string readWord();
	int readNumber();

	std::string getCommand();
	int getNumber();
};

#endif
