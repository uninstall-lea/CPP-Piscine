#pragma once

#include <stack>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <iterator>
#include <exception>


class RPNCalculator {
private:
	static double 				left, right;
	static std::stack<double>	stack;

public:
	/* Error handling */
	static bool 				isStackNotEmpty( void );
	static bool 				isValidExpression( void );
	static bool					isBadInput( std::string& token );
	static bool			 		isValidOperator( const std::string& token );

	/* Printing result of operations */
	static void 				printResult( void );

	/* Core functions */
	static void					performOperation( const char& op );
	static void 				reversePolishNotation( char *av1 );
};