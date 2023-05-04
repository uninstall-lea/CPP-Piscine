#include "Harl.hpp"

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

void	Harl::debug ( void ) {

	std::cout	<< "[ DEBUG ]\n"
				<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n"
				<< "I really do !\n"
				<< std::endl;
}

void	Harl::info ( void ) {

	std::cout	<< "[ INFO ]\n"
				<< "I cannot believe adding extra bacon costs more money.\n"
				<< "You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !\n"
				<< std::endl;
}

void	Harl::warning ( void ) {

	std::cout	<< "[ WARNING ]\n"
				<< "I think I deserve to have some extra bacon for free.\n"
				<< "I’ve been coming for years whereas you started working here since last month.\n"
				<< std::endl;
}

void	Harl::error( void ) {

	std::cout	<< "[ ERROR ]\n"
				<< "This is unacceptable ! I want to speak to the manager now.\n"
				<< std::endl;
}

/* -------------------------------------------------------------------------- */
/*                           Public member function                           */
/* -------------------------------------------------------------------------- */

eLevel		Harl::hashIt( std::string const& level ) {

	if (level == "DEBUG") return (eDEBUG);
	else if (level == "INFO") return (eINFO);
	else if (level == "WARNING") return (eWARNING);
	else if (level == "ERROR") return (eERROR);
	
	return (eNOTFOUND);
}

void	Harl::complain( std::string const& level ) {

	switch (hashIt(level))
	{
		case eDEBUG :
			debug();
			/* fall through */
		case eINFO :
			info();
			/* fall through */
		case eWARNING :
			warning();
			/* fall through */
		case eERROR :
			error();
			break;
		default :
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}