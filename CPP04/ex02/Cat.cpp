#include "Cat.hpp"

/* -------------------------------------------------------------------------- */
/*                          Constructor / Destructor                          */
/* -------------------------------------------------------------------------- */

Cat::Cat( void ) : AAnimal() {

	type = "Cat";
	kittyBrain = new Brain;
	std::cout	<< "Cat: Default constructor called" << std::endl;
}

Cat::Cat( Cat const& src ) : AAnimal(src) {

	kittyBrain = NULL;
	*this = src;

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

	if (kittyBrain)
		delete kittyBrain;
	kittyBrain = new Brain(*rhs.kittyBrain);

	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                                  Function                                  */
/* -------------------------------------------------------------------------- */

void	Cat::makeSound( void ) {

	std::cout << "~Meow, meow !~" << std::endl;
}

std::string const&	Cat::getIdea( int idx ) const {

	return (kittyBrain->getIdea(idx));
}

void	Cat::setIdea( int idx, std::string newIdea ) {

	kittyBrain->setIdea(idx, newIdea);
}