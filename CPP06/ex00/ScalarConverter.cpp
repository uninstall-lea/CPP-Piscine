#include "ScalarConverter.hpp"
#include <iomanip>
/* -------------------------------------------------------------------------- */
/*                                Checking type                               */
/* -------------------------------------------------------------------------- */

bool	ScalarConverter::isChar( std::string literal ) {

	if (literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'' && isprint(literal[1]))
		return (true);

	if (literal.size() == 1 && isprint(literal[0]) && !isdigit(literal[0]))
		return (true);

	return (false);
}

bool	ScalarConverter::isInt( std::string literal ) {

	std::string::iterator it = literal.begin();

	if (*it == '-' || *it == '+')
		it++;
	for (; it != literal.end(); it++)
		if (!isdigit(*it))
			return (false);

	return (true);
}

bool	ScalarConverter::isFloat( std::string literal ) {

	std::string::iterator it = literal.begin();
	int nDot = 0;
	int	nNb = 0;

	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return (true);

	if (*it == '-' || *it == '+')
		it++;

	for (; it != literal.end() - 1; it++) {
		if (*it == '.') 
			nDot++, it++;
		if (!isdigit(*it))
			return (false);
		else
			nNb++;
	}
	return (nDot == 1 && nNb && *it == 'f');
}

bool	ScalarConverter::isDouble( std::string literal ) {

	std::string::iterator it = literal.begin();
	int nDot = 0;
	int	nNb = 0;

	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return (true);

	if (*it == '-' || *it == '+')
		it++;

	for (; it != literal.end(); it++) {
		if (*it == '.') 
			nDot++, it++;
		if (!isdigit(*it))
			return (false);
		else
			nNb++;
	}

	return (nDot == 1 && nNb);
}

/* -------------------------------------------------------------------------- */
/*                                  Printing                                  */
/* -------------------------------------------------------------------------- */

void	ScalarConverter::print( std::string literal ) {

	char	c;
	int		i;
	float	f;
	double	d;

	//Char ----------------------------------
	
	if (isChar(literal)) {
		if (literal.size() == 1)
			c = literal[0];
		else if (literal.size() == 3)
			c = literal[1];

		std::cout << "char: '"	<< c << "'"						<< std::endl;
		std::cout << "int: "	<< static_cast<int>(c)			<< std::endl;
		std::cout << std::fixed << std::setprecision(1) 		<< "float: " << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: "	<< static_cast<double>(c)		<< std::endl;

	}

	//Int ----------------------------------
	
	else if (isInt(literal)) {
		i = atoi(literal.c_str());

		/* checking char */
		if (i < 0 || i > 127)
			std::cout << "char: Impossible"					<< std::endl;
		else if (i < 32 || i > 126)
			std::cout << "char: Not displayable"			<< std::endl;
		else
			std::cout << "char: '" << static_cast<char>(i)	<< "'" << std::endl;

		/* checking int */
		if (atol(literal.c_str()) < INT_MIN || atol(literal.c_str()) > INT_MAX)
			std::cout << "int: Impossible"	<< std::endl;
		else
			std::cout << "int: " 	<< i	<< std::endl;

		/* not check */
		std::cout << std::fixed << std::setprecision(1)		<< "float: " << static_cast<float>(i) << "f" << std::endl;
		std::cout << "double: "	<< static_cast<double>(i)	<< std::endl;
	}

	//Float ---------------------------------

	else if (isFloat(literal)) {
		f = atof(literal.c_str());

		/* checking char */
		if (f < 0 || f > 127)
			std::cout << "char: Impossible"					<< std::endl;
		else if (f < 32 || f > 126)
			std::cout << "char: Not displayable"			<< std::endl;
		else
			std::cout << "char: '" << static_cast<char>(f)	<< "'" << std::endl;

		/* checking int */
		if (f < INT_MIN || f > INT_MAX)
			std::cout << "int: Impossible"					<< std::endl;
		else
			std::cout << "int: " << static_cast<int>(f)		<< std::endl;

		/* no check */
		std::cout << std::fixed << std::setprecision(1) 	<< "float: " << f << "f" << std::endl;
		std::cout << "double: "	<< static_cast<double>(f)	<< std::endl;
	}

	//Double ---------------------------------

	else if (isDouble(literal)) {
		d = atof(literal.c_str());

		/* checking char */
		if (d < 0 || d > 127)
			std::cout << "char: Impossible"					<< std::endl;
		else if (d < 32 || d > 126)
			std::cout << "char: Not displayable"			<< std::endl;
		else
			std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

		/* checking int */
		if (d < INT_MIN || d > INT_MAX)
			std::cout << "int: Impossible"					<< std::endl;
		else
			std::cout << "int: " << static_cast<int>(d)		<< std::endl;

		/* cheking float */
		if (d < FLT_MIN || d > FLT_MAX)
			std::cout << "float: Impossible"				<< std::endl;
		else
			std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(d) << "f" << std::endl;

		/* no check */
		std::cout << "double: "	<< d						<< std::endl;
	}

	else
		std::cout << "Input not correct" << std::endl;
}