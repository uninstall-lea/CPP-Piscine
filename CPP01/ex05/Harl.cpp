#include "Harl.hpp"

const std::string	Harl::_levels[5] = { "DEBUG", "INFO", "WARNING", "ERROR" };
funPtr				Harl::_funPtr[5] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

/* -------------------------------------------------------------------------- */
/*                                 Const/Destr                                */
/* -------------------------------------------------------------------------- */

Harl::Harl( void ) {

}

Harl::~Harl ( void ) {

}

/* -------------------------------------------------------------------------- */
/*                          Private member functions                          */
/* -------------------------------------------------------------------------- */

void	Harl::info ( void ) {

	std::cout << "info called" << std::endl;
}

void	Harl::error( void ) {

	std::cout << "error called" << std::endl;
}

void	Harl::debug ( void ) {

	std::cout << "debug called" << std::endl;
}

void	Harl::warning ( void ) {

	std::cout << "warning called" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                           Public member function                           */
/* -------------------------------------------------------------------------- */

void	Harl::complain( std::string level ) {

	for	(size_t i = 0; i < 4; i++)
		if (level == this->_levels[i])
			(this->*_funPtr[i])();
}