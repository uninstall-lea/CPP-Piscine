#include "AAnimal.hpp"

/* -------------------------------------------------------------------------- */
/*                          Constructor / Destructor                          */
/* -------------------------------------------------------------------------- */

AAnimal::AAnimal( void ) : type("AAnimal") {

	std::cout	<< "AAnimal: Default constructor called" << std::endl;
}

AAnimal::AAnimal( AAnimal const& src ) {

	*this = src;
	std::cout	<< "AAnimal: Copy constructor called" << std::endl;	
}

AAnimal::~AAnimal( void ) {

	std::cout	<< "AAnimal: Destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                            Assignation Operator                            */
/* -------------------------------------------------------------------------- */

AAnimal&	AAnimal::operator=( AAnimal const& rhs ) {

	type = rhs.type;
	
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                                  Functions                                 */
/* -------------------------------------------------------------------------- */

void	AAnimal::makeSound( void ) {

	std::cout << "~AAnimal sound !~" << std::endl;
}

std::string	AAnimal::getType( void ) {

	return (type);
}
