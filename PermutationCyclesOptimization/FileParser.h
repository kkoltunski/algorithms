#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <string>
#include <fstream>
#include <exception>
#include <algorithm>
#include <vector>

class ElephantsData;

class FileParser : public std::fstream
{
public:
	FileParser(const char* _dataArray, ElephantsData* _destination);
	~FileParser();

	void openFile();
	void parseFile();

private:
	bool isPathValid();

	std::string pathToFile;
	ElephantsData* const elephants;
};

#endif // FILEPARSER_H
