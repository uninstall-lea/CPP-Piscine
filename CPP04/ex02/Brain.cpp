#include "Brain.hpp"
#include <algorithm>

/* -------------------------------------------------------------------------- */
/*                          Constructor / Destructor                          */
/* -------------------------------------------------------------------------- */

Brain::Brain( void ) {

	std::cout	<< "Brain: Default constructor called" << std::endl;
}

Brain::Brain( Brain const& src ) {

	*this = src;
	std::cout	<< "Brain: Copy constructor called" << std::endl;
}

Brain::~Brain( void ) {

	std::cout	<< "Brain: Destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                            Assignation Operator                            */
/* -------------------------------------------------------------------------- */


Brain&	Brain::operator=( Brain const& rhs ) {

	for(int i = 0; i < 100; i++)
		ideas[i] = rhs.ideas[i];
	return (*this);
}

std::string const&	Brain::getIdea( int idx ) const {

	return (ideas[idx]);
}

void	Brain::setIdea( int idx, std::string newIdea ) {

	ideas[idx] = newIdea;
}