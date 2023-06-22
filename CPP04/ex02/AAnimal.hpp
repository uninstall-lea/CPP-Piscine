#pragma once

#include <string>
#include <iostream>

class	AAnimal {

	private:

	protected:
		std::string		type;

	public:
						AAnimal( void );
						AAnimal( AAnimal const& src );
		virtual			~AAnimal( void );

		AAnimal&		operator=( AAnimal const& rhs );

		std::string		getType( void );
		virtual void	makeSound( void ) = 0;

};

