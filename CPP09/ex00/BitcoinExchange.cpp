#include "BitcoinExchange.hpp"

/* -------------------------------------------------------------------------- */
/*                             Initializing fields                            */
/* -------------------------------------------------------------------------- */
/* To parse and map data base */
float		BTC::_value;
map_t		BTC::_btcDB, BTC::_infDB;
std::string	BTC::_line, BTC::_date;


/* -------------------------------------------------------------------------- */
/*                               Error Handling                               */
/* -------------------------------------------------------------------------- */

bool	BTC::isDateValid( std::string date ) {

	std::time_t	time		= std::time(NULL);
	struct tm	timeStruct	= *std::localtime(&time);

	if (!strptime(date.c_str(), "%Y-%m-%d", &timeStruct))
		return (false);
	
	int	year = timeStruct.tm_year + 1900;
	int	month = timeStruct.tm_mon + 1;
	int	day	 = timeStruct.tm_mday;

	if (year < 2009 || year > 2023 || month < 1 || month > 12 || day < 1 || day > 31)
		return (false);

	return (true);
}

bool	BTC::isValueInRange( float value ) {

	return (value >= 0.0f && value <= 1000.0f);
}



/* -------------------------------------------------------------------------- */
/*                      Parsing and initiating data bases                     */
/* -------------------------------------------------------------------------- */

void	BTC::readBtcDatabase( void ) {

	std::ifstream	btcFile("data.csv");

	if (!btcFile)
		std::cerr << "Error => could not open: 'data.csv'" << std::endl;

	getline(btcFile, _line);
	if (_line != "date,exchange_rate")
		std::cerr << "Bad input => head line 'date,exchange_rate' missing" << std::endl;

	while (getline(btcFile, _line)) {
		std::istringstream iss(_line);
		getline(iss, _date, '|');
		iss >> _value;
		if (isDateValid(_date) && isValueInRange(_value))
				_btcDB[_date] = _value;
		else
			std::cerr << "Bad format in file => '" + _line + "'" << std::endl;
	}
}

void	BTC::readInputFile( char* av1 ) {

	std::ifstream	inFile(av1);

	if (!inFile)
		std::cerr << "Error => could not open: '" + std::string(av1) + "'" << std::endl;

	getline(inFile, _line);
	if (_line != "date | value")
		std::cerr << "Bad input => head line 'date | format' is missing" << std::endl;

	while (getline(inFile, _line)) {
		std::istringstream iss(_line);
		getline(iss, _date, '|');
		iss >> _value; 
		if (isDateValid(_date) && isValueInRange(_value))
				_infDB[_date] = _value;
		else
			std::cerr << "Bad format in file => '" + _line + "'" << std::endl;
	}
}


/* -------------------------------------------------------------------------- */
/*                                    Utils                                   */
/* -------------------------------------------------------------------------- */
/* Search the */
void	BTC::printExchangeRate( std::ostream& out ) {

	map_t::const_iterator ite = _infDB.begin();
	map_t::const_iterator key;

	for (; ite != _infDB.end(); ite++) {
		_date	= ite->first;
		key  	= _btcDB.lower_bound(_date);
		if (key == _btcDB.end())
			key--;
		_value	= key->second;
		int nb	= ite->second;
		out	<< _date << " => " << nb << " = " << std::setprecision(0) << _value * nb << std::endl;
	}
}