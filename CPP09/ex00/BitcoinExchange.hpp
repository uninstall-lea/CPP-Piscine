#pragma once

// Standard C++ libraries for I/O operations
#include <fstream>
#include <iostream>
#include <sstream>
// Standard C++ libraries for string and container manipulation
#include <map>
#include <string>
// Standard C++ libraries for formatting
#include <iomanip>
// Standard C++ libraries for time
#include <ctime>
// Standard C++ libraries for exceptions
#include <exception>

/* Typedef */
typedef	std::map<std::string, float> map_t;


class	BitcoinExchange {

	private:
		map_t				_btcDB;
		map_t				_infileDB;

	public:

							BitcoinExchange( void );
							BitcoinExchange(const BitcoinExchange& rhs);
			 				BitcoinExchange& operator=(const BitcoinExchange& rhs);
							~BitcoinExchange();

		struct tm			timeStruct;
		int					year;
		int					month;
		int					day;

		/* Getters */
		map_t const&		getInfileDB( void ) const;
		std::string const&	getInfileDate( map_t::const_iterator it ) const;
		float const&		getInfileValue( map_t::const_iterator it ) const;
		float				getBitcoinRate( map_t::const_iterator it ) const;
		float				getExchangeRate( map_t::const_iterator it ) const;

		/* Parsing */
		void				readDate( map_t& _DB, std::string const& sDate );
		void				readValue( map_t& _DB, std::string const& sDate, std::string const& sValue );
		void				readBitcoinDB( void );
		void				readInfile( std::string const& filename );

		/* Formating */
		void				outFormat( std::ostream& out ) const;

};

std::ostream& 				operator<<(std::ostream& out, BitcoinExchange const& rhs);
size_t						separatorPos( std::string const& line, std::string const& sep);
