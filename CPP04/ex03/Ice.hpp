#pragma once

#include <string>
#include <iostream>
#include "AMateria.hpp"

class	Ice : public AMateria {

	public:
					Ice( void );
					Ice( Ice const& src );
					Ice& operator=( Ice const& rhs );
					~Ice( void );

		AMateria*	clone( void ) const;
};
