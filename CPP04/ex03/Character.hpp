#pragma once

#include <string>
#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class AMateria;

class	Character : public ICharacter {

	private:
		std::string			_name;
		AMateria*			_items[4];

	public:
							Character( void );
							Character ( std::string name );
							Character( Character const& src );
							Character& operator=( Character const& rhs );
							~Character( void );

		std::string const&	getName( void ) const;
		void				equip(AMateria* m);
		void 				unequip(int idx);
		void 				use(int idx, ICharacter& target);
};
