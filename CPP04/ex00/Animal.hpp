#pragma once

#include <string>
#include <iostream>

class	Animal {

	private:
		
	protected:
		std::string		type;

	public:
						Animal( void );
						Animal( Animal const& src );
		virtual			~Animal( void );

		Animal&			operator=( Animal const& rhs );

		std::string		getType( void );
		virtual	 void	makeSound( void );
};

