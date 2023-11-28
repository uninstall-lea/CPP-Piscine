#include "BitcoinExchange.hpp"

/* -------------------------------------------------------------------------- */
/*                          Constructor / Destructor                          */
/* -------------------------------------------------------------------------- */

BitcoinExchange::BitcoinExchange( void ) {

	std::time_t t	= std::time(NULL);
    _timeStruct 	= *std::localtime(&t);
	_year			= _timeStruct.tm_year + 1899;
	_month 			= _timeStruct.tm_mon + 1;
	_day			= _timeStruct.tm_mday;

// 'tm' structure stores time, with 'tm_year' representing years since 1900.
// In 2023, 'tm_year' is 123 (2023 - 1900).
// Our BTC database covers up to 2022, so we subtract one year (123 - 1) or (2023 - 1).
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
	: _btcDB(src._btcDB), _infDB(src._infDB)
	, _timeStruct(src._timeStruct), _year(src._year), _month(src._month), _day(src._day) {

}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {

	/* Initialize time */
	_timeStruct	= rhs._timeStruct;
	_year		= rhs._year;
	_month		= rhs._month;
	_day		= rhs._day;

	return (*this) ;
}

BitcoinExchange::~BitcoinExchange() {

}

/* -------------------------------------------------------------------------- */
/*                                   Parsing                                  */
/* -------------------------------------------------------------------------- */
/* --------------------------- * Checking files * --------------------------- */
void	BitcoinExchange::checkBtcFile( void ) {

	std::string		line;
	std::ifstream	btcFile("data.csv");

	if (!btcFile.is_open())
		btcFile.close(), throw std::runtime_error("Could not open 'data.csv'");

	getline(btcFile, line);
	if (btcFile.eof())
		btcFile.close(), throw std::runtime_error("File is empty");

	if (line  != "date,exchange_rate")
		btcFile.close(), throw std::invalid_argument("Bad format in file: 'date,exchange_rate' expected");

}

void	BitcoinExchange::checkInfile( std::string const& filename ) {

	std::string 	line;
	std::ifstream	inFile(filename.c_str());

	if (!inFile.is_open())
		inFile.close(), throw std::runtime_error("Could not open input file: '" + filename + "\'");

	getline(inFile, line);
	if (inFile.eof())
		inFile.close(), throw std::runtime_error("File is empty");

	if (line  != "date | value")
		inFile.close(), throw std::invalid_argument("Bad format in file: 'date | value' expected");
}

/* ---------------------------- * Checking data * --------------------------- */

// Read and parse the data base 
void	BitcoinExchange::readBtcFile( std::ifstream& btcFile ) {

	float			value;
	std::string		line, date;


	while (getline(btcFile, line)) {
		try {
			date = trimSpaces(line, isDate);
			value = checkValueRange(trimSpaces(line, isValue));
			_btcDB[date] = value;
		}
		catch (std::exception const& e) {
			std::cerr << e.what() << std::endl;
		}
	}
}

// Read and parse the given file 
void	BitcoinExchange::readInFile(std::ifstream& inFile ) {

	float			value;
	std::string		line, date;

	while (getline(inFile, line)) {
		try {
			date = trimSpaces(line, isDate);
			checkDateFormat(date);
			value = checkValueRange(trimSpaces(line, isValue));
			_infDB[date] = value;
		}
		catch (std::exception const& e) {
			std::cerr << e.what() << std::endl;
		}
	}
}

// Read and parse date
void	BitcoinExchange::checkDateFormat( std::string const& sDate ) {

	std::istringstream	timeSS(sDate);
	char* end = strptime(sDate.c_str(), "%Y-%m-%d", &_timeStruct);

   if (end != sDate.c_str() + sDate.size())
		throw std::invalid_argument("Bad format in file: 'Year-_month-_day' expected: " + sDate);

	if (_year < 2009 || _year > 2022 || _month < 1 || _month > 12 || _day < 1 || _day > 31) {
		throw std::invalid_argument("Bad format in file: invalid format date: " + sDate);
	}
}

// Read and parse the file value
float	BitcoinExchange::checkValueRange( std::string const& sValue ) {

	float				value;
	std::istringstream	iss(sValue);

	iss >> value;
	if (value < 0.0f || value > 1000.0f)
		throw std::invalid_argument("Bad format in file: value must be between '0-1000': " + sValue);

	return (value);
}

/* -------------------------------------------------------------------------- */
/*                                   Getters                                  */
/* -------------------------------------------------------------------------- */
const map_t& BitcoinExchange::getInfDB( void ) const {

	return (_infDB);
} 

const std::string& BitcoinExchange::getInfDate( map_t::const_iterator it ) const {

	return (it->first);
}

const float& BitcoinExchange::getInfValue( map_t::const_iterator it ) const {

	return (it->second);
}

float BitcoinExchange::getBtcRate( map_t::const_iterator it ) const {

	map_t::const_iterator	btcRateIt = _btcDB.lower_bound(getInfDate(it));
	//If the key is not find in the map, get the previous iterator
	if (btcRateIt == _btcDB.end())
		btcRateIt--;
	return (btcRateIt->second);

}

float BitcoinExchange::getExchangeRate( map_t::const_iterator it ) const {

	return (getBtcRate(it) * getInfValue(it));
}

/* ------------------------------- * Stream * ------------------------------- */
void	BitcoinExchange::outFormat( std::ostream& out ) const {

	map_t::const_iterator it = getInfDB().begin();

	for (; it != getInfDB().end(); it++) {
	out << getInfDate( it ) << " => "
		<< getInfValue( it ) << " = " << getExchangeRate( it )
		<< std::endl; 
	}
}
