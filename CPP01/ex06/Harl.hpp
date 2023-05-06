#pragma once

#include <iostream>

enum	eLevel {

	eDEBUG,
	eINFO,
	eWARNING,
	eERROR,
	eNOTFOUND
};

class	Harl {

	private:

		void	info( void );
		void	error( void );
		void	debug( void );
		void	warning( void );

	public:
		Harl( void );
		~Harl ( void );

		eLevel	hashIt( std::string const& level);
		void	complain( std::string const& level );

};

