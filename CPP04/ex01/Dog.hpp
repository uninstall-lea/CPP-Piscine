#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal {

	private:
		Brain*	doggyBrain;

	public:
							Dog( void );
							Dog( Dog const& src );
							~Dog( void );

		Dog&				operator=( Dog const& rhs );

		std::string const&	getIdea( int idx ) const;
		void				setIdea( int idx, std::string newIdea );

		void				makeSound( void );
};
