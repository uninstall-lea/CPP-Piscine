#include "WrongCat.hpp"

/* -------------------------------------------------------------------------- */
/*                          Constructor / Destructor                          */
/* -------------------------------------------------------------------------- */

WrongCat::WrongCat( void ) : WrongAnimal() {

	type = "WrongCat";
	std::cout	<< "WrongCat: Default constructor called" << std::endl;
}

WrongCat::WrongCat( WrongCat const& src ) : WrongAnimal(src) {

	type = src.type;
	std::cout	<< "WrongCat: Copy constructor called" << std::endl;
}

WrongCat::~WrongCat( void ) {

	std::cout 	<< "WrongCat: Destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                            Assignation Operator                            */
/* -------------------------------------------------------------------------- */

WrongCat&	WrongCat::operator=( WrongCat const& rhs ) {

	type = rhs.type;
	return (*this);
}
