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
						~WrongAnimal( void );

		WrongAnimal&	operator=( WrongAnimal const& rhs );

		std::string		getType( void );
		void			makeSound( void );
};
