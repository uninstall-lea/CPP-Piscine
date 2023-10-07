#include "Dog.hpp"

/* -------------------------------------------------------------------------- */
/*                          Constructor / Destructor                          */
/* -------------------------------------------------------------------------- */

Dog::Dog( void ) : Animal() {

	type = "Dog";
	doggyBrain = new Brain;
	std::cout	<< "Dog: Default constructor called" << std::endl;
}

Dog::Dog( Dog const& src ) : Animal(src) {

	doggyBrain = NULL;
	*this = src;
	
	std::cout	<< "Dog: Copy constructor called" << std::endl;
}

Dog::~Dog( void ) {

	delete doggyBrain;
	std::cout	<< "Dog: Destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                            Assignation Operator                            */
/* -------------------------------------------------------------------------- */

Dog&	Dog::operator=( Dog const& rhs ) {

	type = rhs.type;

	if (doggyBrain)
		delete doggyBrain;
	doggyBrain = new Brain(*rhs.doggyBrain);

	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                                  Function                                  */
/* -------------------------------------------------------------------------- */

void	Dog::makeSound( void ) {

	std::cout << "~Woof, woof !~" << std::endl;
}

std::string const&	Dog::getIdea( int idx ) const {

	return (doggyBrain->getIdea(idx));
}

void	Dog::setIdea( int idx, std::string newIdea ) {

	doggyBrain->setIdea(idx, newIdea);
}