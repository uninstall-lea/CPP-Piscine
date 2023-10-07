#include "Ice.hpp"

/* -------------------------------------------------------------------------- */
/*                          Constrcutor / Destructor                          */
/* -------------------------------------------------------------------------- */

Ice::Ice( void ) : AMateria() {

	type = "ice";
}
Ice::Ice( Ice const& src ) : AMateria() {

	*this = src;
}

Ice& Ice::operator=( Ice const& rhs ) {

	type = rhs.type;

	return (*this);
}

Ice::~Ice( void ) {

}

/* -------------------------------------------------------------------------- */
/*                                  Functions                                 */
/* -------------------------------------------------------------------------- */

AMateria* Ice::clone( void ) const {

	AMateria* materia = new Ice();

	return (materia);
}
