#include <exception>
#include <iostream>
#include <fstream>
#include <string>
#include <map>

void readInFile(const std::string &filename) {

	std::ifstream	inFile(filename);
	std::string		line;

	if (!inFile.is_open())
		throw std::runtime_error("An error occured while opening the file");

	getline(inFile, line);
	if (line.compare("date | value") != true)
			throw std::invalid_argument("Bad format in file: 'date | value' expected");

	while (getline(inFile, line)) {
		checkDate(line);
		checkValue(line);
	}
}

void calculateBitcoinValue(void) {
    // TODO
}
