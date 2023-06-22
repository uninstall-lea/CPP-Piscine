#include "AMateria.hpp"

/* -------------------------------------------------------------------------- */
/*                          Constrcutor / Destructor                          */
/* -------------------------------------------------------------------------- */

AMateria::AMateria( void ) {

}

AMateria::AMateria( std::string const& type ) {

	this->type = type;
}

AMateria::~AMateria( void ) {

}

/* -------------------------------------------------------------------------- */
/*                                  Functions                                 */
/* -------------------------------------------------------------------------- */

std::string	const&	AMateria::getType( void ) const {

}

void		AMateria::use( ICharacter& target ) {

}