#include "Harl.hpp"

int	main( void ) {

	Harl		harl;
	std::string	level;

	do
	{
		std::cout	<< "You must enter a level such as: "
					<< "DEBUG, INFO, WARNING, ERROR." << std::endl;
		std::getline(std::cin, level);

		if (!std::cin.good())
			return (1);
	
	} while ( level != "DEBUG" && level != "INFO"
			&& level != "WARNING" && level != "ERROR" );

	harl.complain(level);
	return (0);
}