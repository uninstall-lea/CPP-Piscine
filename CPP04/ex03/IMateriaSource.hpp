#pragma once

#include <string>
#include <iostream>
#include "AMateria.hpp"

class	IMateriaSource {

	public:
		virtual				~IMateriaSource( void ) {}
		virtual void		learnMateria( AMateria* ) = 0;
		virtual AMateria*	createMateria( std::string const& type ) = 0;
};
