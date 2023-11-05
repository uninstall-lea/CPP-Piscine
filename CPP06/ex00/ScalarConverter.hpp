#pragma once

#include <string>
#include <iostream>
#include <ctype.h>
#include <limits>
#include <climits>
#include <cfloat>
#include <cmath>

class	ScalarConverter {

	private:
		static bool		isChar( std::string literal );
		static bool		isInt( std::string literal );
		static bool		isFloat( std::string literal );
		static bool		isDouble( std::string literal );

	public:
		static void	print( std::string literal );

};
