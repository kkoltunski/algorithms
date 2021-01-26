#include "FileParser.h"
#include "ElephantsData.h"

FileParser::FileParser(const char* _path, ElephantsData* _destination) :
	pathToFile{ _path }, elephants{ _destination }
{
}

FileParser::~FileParser(){
	close();
}

void FileParser::openFile() {
	if (!is_open()) {
		if (isPathValid()) {
			open(pathToFile, std::ios::in);

			if (!is_open()) {
				throw std::exception{ "Error occur while opening file." };
			}
		}
		else {
			throw std::exception{ "No valid directory." };
		}
	}
}

void FileParser::parseFile() {
	if (is_open()) {
		std::string helpString{};
		std::vector<long int> helpVector{};

		*this >> helpString;
		long elephantsCount = std::stol(helpString);
		helpVector.resize(elephantsCount);

		elephants->initializeData(elephantsCount);
		for (long int i = 0; i < elephantsCount; ++i) {
			*this >> std::skipws >> helpString;
			elephants->assignElephantWeight(i, std::stoi(helpString));
		}
		for (long int i = 0; i < elephantsCount; ++i) {
			*this >> std::skipws >> helpString;
			helpVector[i] = std::stol(helpString);
		}
		elephants->setWorkersSequence(helpVector);
		helpVector.resize(elephantsCount);
		for (long int i = 0; i < elephantsCount; ++i) {
			*this >> std::skipws >> helpString;
			helpVector[i] = std::stol(helpString);
		}
		elephants->setDirectorSequence(helpVector);
	}
}

bool FileParser::isPathValid() {
	bool result{ false };
	size_t exstensionPosition = pathToFile.find_last_of('.');

	if (exstensionPosition != std::string::npos) {
		std::string fileExtension{ pathToFile.substr(exstensionPosition) };
		std::transform(fileExtension.begin(), fileExtension.end(), fileExtension.begin(),
			[](unsigned char c) { return std::tolower(c); });

		if (fileExtension.compare(".in") == 0) {
			result = true;
		}
	}

	return result;
}