#pragma once

#include <iostream>

class	Weapon {

	private:
		std::string _type;

	public:
		Weapon( void );
		Weapon( std::string );
		~Weapon ( void );

		std::string const &	getType( void ) const;
		void				setType( std::string const & );
};