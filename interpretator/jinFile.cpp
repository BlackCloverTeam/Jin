#include "jinFile.h"

jinFile::jinFile()
{
	this->filename = "";
}

jinFile::jinFile(std::string _filename)
{
	this->filename = _filename;
}

bool jinFile::isRightName()
{
	std::regex right_name("(.{1,})\\.jin");

	return std::regex_match(this->filename, right_name);
}

bool jinFile::isEof()
{
	return this->file_reader.eof();
}

bool jinFile::open()
{
	this->file_reader.open(filename);

	return !this->file_reader.fail();
}

void jinFile::setFilename(std::string _filename)
{
	this->filename = _filename;
}

std::string jinFile::readWord()
{
	this->file_reader >> this->command_str;

	return this->command_str;
}

int jinFile::readNumber()
{
	file_reader >> this->number;

	return this->number;
}

std::string jinFile::getCommand()
{
	return this->command_str;
}

int jinFile::getNumber()
{
	return this->number;
}