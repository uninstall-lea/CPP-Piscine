#include "Animal.hpp"

/* -------------------------------------------------------------------------- */
/*                          Constructor / Destructor                          */
/* -------------------------------------------------------------------------- */

Animal::Animal( void ) : type("Animal") {

	std::cout	<< "Animal: Default constructor called" << std::endl;
}

Animal::Animal( Animal const& src ) : type(src.type) {

	std::cout	<< "Animal: Copy constructor called" << std::endl;	
}

Animal::~Animal( void ) {

	std::cout	<< "Animal: Destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                            Assignation Operator                            */
/* -------------------------------------------------------------------------- */

Animal&	Animal::operator=( Animal const& rhs ) {

	type = rhs.type;

	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                                  Functions                                 */
/* -------------------------------------------------------------------------- */

void	Animal::makeSound( void ) {

	std::cout << "~Animal sound !~" << std::endl;
}

std::string	Animal::getType( void ) {

	return (type);
}
