#include "WrongAnimal.hpp"

/* -------------------------------------------------------------------------- */
/*                          Constructor / Destructor                          */
/* -------------------------------------------------------------------------- */

WrongAnimal::WrongAnimal( void ) : type("WrongAnimal") {

	std::cout	<< "WrongAnimal: Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const& src ) : type(src.type) {

	std::cout	<< "WrongAnimal: Copy constructor called" << std::endl;	
}

WrongAnimal::~WrongAnimal( void ) {

	std::cout	<< "WrongAnimal: Destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                            Assignation Operator                            */
/* -------------------------------------------------------------------------- */

WrongAnimal&	WrongAnimal::operator=( WrongAnimal const& rhs ) {

	type = rhs.type;

	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                                  Functions                                 */
/* -------------------------------------------------------------------------- */

void	WrongAnimal::makeSound( void ) {

	std::cout	<< "~WrongAnimal sound !~" << std::endl;
}

std::string	WrongAnimal::getType( void ) {

	return (type);
}
