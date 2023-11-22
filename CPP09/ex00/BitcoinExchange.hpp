#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, double> data;

	public:
				BitcoinExchange( void );
				BitcoinExchange( const BitcoinExchange &src );
				~BitcoinExchange( void );

				BitcoinExchange& operator=( const BitcoinExchange &src );

		/* methods */
		void	readInputFile( const std::string &filename );
		void	calculateBitcoinValue( void );
};

