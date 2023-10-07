#include "AMateria.hpp"

/* -------------------------------------------------------------------------- */
/*                          Constrcutor / Destructor                          */
/* -------------------------------------------------------------------------- */

AMateria::AMateria( void ) {

}

AMateria::AMateria( std::string const& type ) {

	this->type = type;
}

AMateria&	AMateria::operator=( AMateria const& rhs ) {

	*this = *rhs.clone();

	return (*this);
}

AMateria::~AMateria( void ) {

}

void	AMateria::use( ICharacter& target ) {

	if (getType() == "ice")
		std::cout	<< "* shoots an ice bolt at " << target.getName() << " *" << std::endl;

	else if (getType() == "cure")
		std::cout	<< "* heals " << target.getName() << "'s wounds *" << std::endl;
}

std::string const&	AMateria::getType() const {

	return (type);
}