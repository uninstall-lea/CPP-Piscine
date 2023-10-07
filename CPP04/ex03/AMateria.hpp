#pragma once

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class	AMateria {

	protected:
		std::string			type;

	public:
							AMateria( void );
							AMateria( std::string const& type );
							AMateria& operator=( AMateria const& rhs );
		virtual				~AMateria( void );

		std::string	const&	getType( void ) const;

		virtual AMateria*	clone( void ) const = 0;
		virtual	void		use( ICharacter& target );

};
