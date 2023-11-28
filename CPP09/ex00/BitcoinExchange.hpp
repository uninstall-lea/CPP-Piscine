#pragma once

// Standard C++ libraries for I/O operations
#include <fstream>
#include <iostream>
#include <sstream>
// Standard C++ libraries for string and container manipulation
#include <map>
#include <string>
#include <algorithm>
// Standard C++ libraries for formatting
#include <iomanip>
// Standard C++ libraries for time
#include <ctime>
// Standard C++ libraries for exceptions
#include <exception>

/* Defines */
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define isDate 1
#define isValue 0

/* Typedef */
typedef	std::map<std::string, float> map_t;

class	BitcoinExchange {

	private:
		map_t				_btcDB;
		map_t				_infDB;
		struct tm			_timeStruct;
		int					_year;
		int					_month;
		int					_day;

	public:

							BitcoinExchange( void );
							BitcoinExchange(const BitcoinExchange& src);
			 				BitcoinExchange& operator=(const BitcoinExchange& rhs);
							~BitcoinExchange();

		/* Getters */
		const map_t &		getInfDB( void ) const;
		const std::string&	getInfDate( map_t::const_iterator it ) const;
		const float&		getInfValue( map_t::const_iterator it ) const;
		float				getBtcRate( map_t::const_iterator it ) const;
		float				getExchangeRate( map_t::const_iterator it ) const;


		/* Parsing */
		void				checkDateFormat( std::string const& sDate );
		float				checkValueRange( std::string const& sValue );
		void				readBtcFile( std::ifstream& btcFile );
		void				readInFile( std::ifstream& inFile );

		/* Stream */
		void				outFormat( std::ostream& out ) const;
};

/* File checking */
void						checkBtcFile( void );
void						checkInfile( std::string const& filename );
/* Non Member Utils */
std::ostream& 				operator<<(std::ostream& out, BitcoinExchange const& rhs);
size_t						separatorPos( std::string const& line, std::string const& sep);
std::string					trimSpaces( std::string line, std::string sep,bool part );