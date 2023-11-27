#include "BitcoinExchange.hpp"

/* -------------------------------------------------------------------------- */
/*                          Constructor / Destructor                          */
/* -------------------------------------------------------------------------- */

BitcoinExchange::BitcoinExchange( void ) {

	std::time_t t	= std::time(NULL);
    timeStruct 		= *std::localtime(&t);
	year 			= timeStruct.tm_year + 1990;
	month 			= timeStruct.tm_mon + 1;
	day				= timeStruct.tm_mday;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs)
	: _btcDB(rhs._btcDB), _infileDB(rhs._infileDB)
	, timeStruct(rhs.timeStruct), year(rhs.year), month(rhs.month), day(rhs.day) {

}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {

	_btcDB		= rhs._btcDB;
	_infileDB	= rhs._infileDB;
	timeStruct	= rhs.timeStruct;
	year		= rhs.year;
	month		= rhs.month;
	day			= rhs.day;

	return (*this) ;
}

BitcoinExchange::~BitcoinExchange() {

}

/* -------------------------------------------------------------------------- */
/*                                   Parsing                                  */
/* -------------------------------------------------------------------------- */

// Read and parse date
void	BitcoinExchange::readDate( map_t& _DB, std::string const& sDate ) {

	std::istringstream	timeSS(sDate);
	char* end = strptime(sDate.c_str(), "%Y-%m-%d", &timeStruct);

   if (end != sDate.c_str() + sDate.size())
		throw std::invalid_argument("Bad format in file: 'Year-Month-Day' expected: " + sDate);

	if (year < 2009 || year > 2022 || month < 1 || month > 12 || day < 1 || day > 31)
		throw std::invalid_argument("Bad format in file: invalid format date: " + sDate);

	_DB[sDate] = 0.0f;
}

// Read and parse the value
void	BitcoinExchange::readValue( map_t& _DB, std::string const& sDate, std::string const& sValue ) {

	float				value;
	std::istringstream	iss(sValue);

	iss >> value;
	if (value < 0.0f || value > 1000.0f)
		throw std::invalid_argument("Bad format in file: value must be between '0-1000': " + sValue);

	_DB[sDate] = value;
}

// Read and parse the data base 
void	BitcoinExchange::readBitcoinDB( void ) {

	size_t			pos;
	std::string		line;
	std::ifstream	dbFile("data.csv");

	if (!dbFile.is_open())
		throw std::runtime_error("Could not open 'data.csv'");

	getline(dbFile, line);
	if (dbFile.eof())
		throw std::runtime_error("File is empty");

	if (line  != "date,exchange_rate")
		throw std::invalid_argument("Bad format in file: 'date,exchange_rate' expected");


	while (getline(dbFile, line)) {
		pos = separatorPos(line, ",");
		readDate(_btcDB, line.substr(0, pos));
		readValue(_btcDB, line.substr(0, pos), line.substr(pos + 1));
	}

}

// Read and parse the given file 
void	BitcoinExchange::readInfile( std::string const& filename ) {

	size_t			pos;
	std::string		line;
	std::ifstream	inFile(filename.c_str());

	if (!inFile.is_open())
		throw std::runtime_error("Could not open input file: '" + filename + "\'");

	getline(inFile, line);
	if (inFile.eof())
		throw std::runtime_error("File is empty");

	if (line  != "date | value")
		throw std::invalid_argument("Bad format in file: 'date | value' expected");

	while (getline(inFile, line)) {
		pos = separatorPos(line, "|");
		readDate(_infileDB, line.substr(0, pos));
		readValue(_infileDB, line.substr(0, pos), line.substr(pos + 1));
	}
}

/* -------------------------------------------------------------------------- */
/*                                   Getters                                  */
/* -------------------------------------------------------------------------- */

map_t const& BitcoinExchange::getInfileDB( void ) const {

	return (_infileDB);
} 

std::string const& BitcoinExchange::getInfileDate( map_t::const_iterator it ) const {

	return (it->first);
}

float const& BitcoinExchange::getInfileValue( map_t::const_iterator it ) const {

	return (it->second);
}

float BitcoinExchange::getBitcoinRate( map_t::const_iterator it ) const {

	map_t::const_iterator	btcRateIt = _btcDB.lower_bound(getInfileDate(it));
	//If the key is not find in the map, get the previous iterator
	if (btcRateIt == _btcDB.end())
		btcRateIt--;
	return (btcRateIt->second);

}

float BitcoinExchange::getExchangeRate( map_t::const_iterator it ) const {

	return (getBitcoinRate(it) * getInfileValue(it));
}

/* -------------------------------------------------------------------------- */
/*                             Non members methods                            */
/* -------------------------------------------------------------------------- */

size_t	separatorPos( std::string const& line, std::string const& sep) {

	size_t	pos = line.find(sep.c_str());

	if (pos == std::string::npos)
		throw std::invalid_argument("Bad format in file: separator not found: '" + sep + "\'");
	return (pos);
};

/* ---------------------------- Output formating ---------------------------- */

void	BitcoinExchange::outFormat( std::ostream& out ) const {

	map_t::const_iterator it = getInfileDB().begin();
	for (; it != getInfileDB().end(); it++) {
	out << getInfileDate( it ) << " => "
		<< getInfileValue( it ) << " = " << getExchangeRate( it )
		<< std::endl; 
	}
}

std::ostream& operator<<(std::ostream& out, BitcoinExchange const& rhs) {

	rhs.outFormat(out);
	return (out);
};

