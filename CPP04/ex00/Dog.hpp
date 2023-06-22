#pragma once

#include "Animal.hpp"

class	Dog : public Animal {

	private:


	public:
				Dog( void );
				Dog( Dog const& src );
				~Dog( void );

		Dog&	operator=( Dog const& rhs );

		void	makeSound( void );
};
