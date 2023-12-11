#include "BitcoinExchange.hpp"

/* -------------------------------------------------------------------------- */
/*                             Initializing fields                            */
/* -------------------------------------------------------------------------- */
/* To parse and map data base */
float		BTC::_value;
map_t		BTC::_btcDB;
std::string	BTC::_line, BTC::_date;


/* -------------------------------------------------------------------------- */
/*                               Error Handling                               */
/* -------------------------------------------------------------------------- */

bool	BTC::isDateValid( std::string date ) {

	std::time_t	time		= std::time(NULL);
	struct tm	timeStruct	= *std::localtime(&time);

	if (!strptime(date.c_str(), "%Y-%m-%d", &timeStruct))
		return (std::cerr << "Bad format in file: '" + date + "'\n", false);

	if (date < "2009-01-02")
		return (std::cerr << "Bad input: Date can't be before BTC: 2009-01-02\n", false);

	int	year = timeStruct.tm_year + 1900;
	int	month = timeStruct.tm_mon + 1;
	int	day	 = timeStruct.tm_mday;

	if (year < 2009 || year > 2023 || month < 1 || month > 12 || day < 1 || day > 31)
		return (std::cerr << "Bad input: Invalid date: '" + date + "'\n", false);

	return (true);
}

bool	BTC::isValueInRange( float value ) {

	if (value < 0.0f)
		return std::cerr << "Bad input: Must be a positive number: range is 0-1000\n", false;
	else if (value > 1000.0f) 
		return (std::cerr << "Bad input: Too large a number: range is 0-1000\n", false);

	return (true);
}



/* -------------------------------------------------------------------------- */
/*                      Parsing and initiating data bases                     */
/* -------------------------------------------------------------------------- */

void	BTC::readBtcDatabase( void ) {

	std::ifstream	btcFile("data.csv");

	if (!btcFile) {
		std::cerr << "Error: could not open: 'data.csv'" << std::endl;
		return; 
	}

	getline(btcFile, _line);
	if (_line != "date,exchange_rate")
		std::cerr << "Bad input: head line 'date,exchange_rate' missing" << std::endl;

	while (getline(btcFile, _line)) {
		std::istringstream iss(_line);
		getline(iss, _date, ',');
		iss >> _value;
		if (isDateValid(_date))
			_btcDB[_date] = _value;
	}
}

void	BTC::readInputFile( char* av1 ) {

	std::ifstream	inFile(av1);

	if (!inFile) {
		std::cerr << "Error: could not open: '" + std::string(av1) + "'" << std::endl;
		return; 
	}

	getline(inFile, _line);
	if (_line != "date | value")
		std::cerr << "Bad input: head line 'date | format' is missing" << std::endl;

	while (getline(inFile, _line)) {
		std::istringstream iss(_line);
		getline(iss, _date, '|');
		iss >> _value; 
		if (isDateValid(_date) && isValueInRange(_value))
			printExchangeRate(_date, _value);
	}
}


/* -------------------------------------------------------------------------- */
/*                                    Utils                                   */
/* -------------------------------------------------------------------------- */
void	BTC::printExchangeRate( std::string inDate, float nb ) {

	map_t::const_iterator key = _btcDB.find(inDate);

	if (key == _btcDB.end())
	{
		key = _btcDB.upper_bound(inDate);
		if (key != _btcDB.begin())
			key--;
	}
	double value = key->second;

	std::cout << inDate << " => " << nb << " = " << value * nb << std::endl;
}