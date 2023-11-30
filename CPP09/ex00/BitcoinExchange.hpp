#pragma once

#include <map>
#include <ctime>
#include <string>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <exception>

typedef	std::map<std::string, float> map_t;

typedef class BitcoinExchange {
private:
	static float		_value;
	static map_t		_btcDB, _infDB;
	static std::string	_line, _date;

public:
	/* Error handling */
	static bool			isValueInRange( float value );
	static bool			isDateValid( std::string date );
	static bool			isArgumentValid( const std::string expectedSep );

	/* Parsing */
	static void			readBtcDatabase( void );
	static void			readInputFile( char* av1 );

	static void			printExchangeRate( std::ostream& out );


} BTC;
	/* Printing exchange rates */
	std::ostream& 		operator<<( std::ostream& out, const BitcoinExchange& rate );
