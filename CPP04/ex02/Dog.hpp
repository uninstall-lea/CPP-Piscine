#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class	Dog : public AAnimal {

	private:
		Brain*	doggyBrain;

	public:
				Dog( void );
				Dog( Dog const& src );
				~Dog( void );

		Dog&	operator=( Dog const& rhs );

		void	makeSound( void );
};
