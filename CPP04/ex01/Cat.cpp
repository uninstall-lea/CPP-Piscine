#include "Cat.hpp"

/* -------------------------------------------------------------------------- */
/*                          Constructor / Destructor                          */
/* -------------------------------------------------------------------------- */

Cat::Cat( void ) : Animal() {

	type = "Cat";
	kittyBrain = new Brain;
	std::cout	<< "Cat: Default constructor called" << std::endl;
}

Cat::Cat( Cat const& src ) : Animal(src) {

	type = src.type;
	kittyBrain = new Brain;
	std::cout	<< "Cat: Copy constructor called" << std::endl;
}

Cat::~Cat( void ) {

	delete kittyBrain;
	std::cout	<< "Cat: Destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                            Assignation Operator                            */
/* -------------------------------------------------------------------------- */


Cat&	Cat::operator=( Cat const& rhs ) {

	type = rhs.type;
	kittyBrain = rhs.kittyBrain;
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                                  Function                                  */
/* -------------------------------------------------------------------------- */

void	Cat::makeSound( void ) {

	std::cout << "~Meow, meow !~" << std::endl;
}
