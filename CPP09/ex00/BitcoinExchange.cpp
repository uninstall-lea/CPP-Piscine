#include "BitcoinExchange.hpp"
#include <iostream>

BitcoinExchange::BitcoinExchange( void ) {

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) : data(src.data) {

}

BitcoinExchange::~BitcoinExchange( void ) {

}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {
    this->data = src.data;
    return (*this);
}

/* -------------------------------------------------------------------------- */

void BitcoinExchange::readInputFile(const std::string &filename) {

	std::ifstream file(filename);
	if (!file.is_open())
		throw std::runtime_error("An error occured while opening inputFile");
	std::ifstream dataBase("data.csv");

	if (!dataBase.is_open()) {
		file.close();
		throw std::runtime_error("An error occured while opening data.csv");
	}

	
}

void BitcoinExchange::calculateBitcoinValue( void) {
    // TODO
}
