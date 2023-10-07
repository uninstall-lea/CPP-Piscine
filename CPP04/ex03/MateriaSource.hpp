#pragma once

#include <string>
#include <iostream>
#include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource {

	private:
		AMateria*		_stock[4];
		int				_idx;

	public:
						MateriaSource( void );
						MateriaSource( MateriaSource const& src );
						MateriaSource& operator=( MateriaSource const& rhs );
						~MateriaSource( void );

		void			learnMateria( AMateria* src );
		AMateria*		createMateria( std::string const& type );

};
