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

		Cat&				operator=( Cat const& rhs );

		std::string const&	getIdea( int idx ) const;
		void				setIdea( int idx, std::string newIdea );

		void				makeSound( void );

};
