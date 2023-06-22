#include "Cure.hpp"

/* -------------------------------------------------------------------------- */
/*                          Constrcutor / Destructor                          */
/* -------------------------------------------------------------------------- */

Cure::Cure( void ) : AMateria() {

	type = "Cure";
}
Cure::Cure( Cure const& src ) : AMateria(src) {

	*this = src;
}

Cure& Cure::operator=( Cure const& rhs ) {

	type = rhs.type;
	return (*this);
}

Cure::~Cure( void ) {

}

/* -------------------------------------------------------------------------- */
/*                                  Functions                                 */
/* -------------------------------------------------------------------------- */

AMateria* Cure::clone( void ) const {

	AMateria* materia = new Cure();
	return (materia);
}

void Cure::use( ICharacter& target ) {

	std::cout	<< "Cure: * heals " << target.getName() << "'s wounds *" << std::endl;
}