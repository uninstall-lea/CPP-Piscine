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
	static map_t		_btcDB;
	static std::string	_line, _date;

public:
	/* Error handling */
	static bool			isValueInRange( float value );
	static bool			isDateValid( std::string date );

	/* Parsing */
	static void			readBtcDatabase( void );
	static void			readInputFile( char* av1 );

	static void			printExchangeRate( std::string inDate, float nb );


} BTC;
