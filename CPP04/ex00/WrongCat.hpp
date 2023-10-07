#pragma once

#include "WrongAnimal.hpp"

class	WrongCat : public virtual WrongAnimal {

	private:

	public:
					WrongCat( void );
					WrongCat( WrongCat const& src );
					~WrongCat( void );

		WrongCat&	operator=( WrongCat const& rhs );
};