#pragma once

#include <string>
#include <iostream>
#include "AMateria.hpp"

class	Cure : public AMateria {

	public:
					Cure( void );
					Cure( Cure const& src );
					Cure& operator=( Cure const& rhs );
					~Cure( void );

		AMateria*	clone( void ) const;
		void		use( ICharacter& target );
};