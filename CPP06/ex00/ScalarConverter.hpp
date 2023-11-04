#pragma once

#include <string>
#include <iostream>
#include <ctype.h>
#include <limits>
#include <cmath>

class	ScalarConverter {

	private:
		

	public:
				ScalarConverter( void );
				ScalarConverter( ScalarConverter const& src );
				ScalarConverter& operator=( ScalarConverter const& rhs );
				~ScalarConverter( void );

	bool		isChar( std::string literal );
	bool		isInt( std::string literal );
	bool		isFloat( std::string literal );
	bool		isDouble( std::string literal );


};

/*----------------------------------------------------------------------------*/

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void ) {

}

ScalarConverter::ScalarConverter( ScalarConverter const& src ) {

	*this = src;
}

ScalarConverter::~ScalarConverter( void ) {

}

ScalarConverter&	ScalarConverter::operator=( ScalarConverter const& rhs ) {

	return (*this);
}

bool	ScalarConverter::isChar( std::string literal ) {

#include <typeinfo>

typeid()
}

bool	ScalarConverter::isInt( std::string literal ) {

}

bool	ScalarConverter::isFloat( std::string literal ) {

}

bool	ScalarConverter::isDouble( std::string literal ) {

}

/*----------------------------------------------------------------------------*/
