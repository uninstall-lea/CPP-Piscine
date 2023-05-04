#pragma once

#include <iostream>

class	Harl;
typedef void (Harl::*funPtr)(void);

class	Harl {

	private:
		static const std::string	_levels[5];
		static  funPtr				_funPtr[5];

		void	info( void );
		void	error( void );
		void	debug( void );
		void	warning( void );

	public:
		Harl( void );
		~Harl ( void );

		

		void	complain( std::string level );

};

