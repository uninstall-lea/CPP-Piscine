#pragma once

#include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal {

	private:

	public:
					WrongCat( void );
					WrongCat( WrongCat const& src );
					~WrongCat( void );

		WrongCat&	operator=( WrongCat const& rhs );

		void		makeSound( void );
};