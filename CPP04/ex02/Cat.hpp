#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class	Cat : public AAnimal {

	private:
		Brain*	kittyBrain;

	public:
				Cat( void );
				Cat( Cat const& src );
				~Cat( void );

		Cat&	operator=( Cat const& rhs );

		void	makeSound( void );

};
