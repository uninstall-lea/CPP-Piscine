#include "Dog.hpp"

/* -------------------------------------------------------------------------- */
/*                          Constructor / Destructor                          */
/* -------------------------------------------------------------------------- */

Dog::Dog( void ) : Animal() {

	type = "Dog";
	doggyBrain = new Brain;
	std::cout	<< "Dog: Default constructor called" << std::endl;
}

Dog::Dog( Dog const& src ) :  Animal(src) {

	type = src.type;
	doggyBrain = new Brain;
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
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                                  Function                                  */
/* -------------------------------------------------------------------------- */

void	Dog::makeSound( void ) {

	std::cout << "~Woof, woof !~" << std::endl;
}