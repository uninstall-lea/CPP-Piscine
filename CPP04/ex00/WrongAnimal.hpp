#pragma once

#include <string>
#include <iostream>

class	WrongAnimal {

	private:
		
	protected:
		std::string	type;

	public:
						WrongAnimal( void );
						WrongAnimal( WrongAnimal const& src );
		virtual			~WrongAnimal( void );

		WrongAnimal&	operator=( WrongAnimal const& rhs );

		std::string		getType( void );
		virtual void	makeSound( void );
};
