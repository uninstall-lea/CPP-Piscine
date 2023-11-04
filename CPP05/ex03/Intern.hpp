#pragma once

#include <string>
#include <iostream>
#include "AForm.hpp"

class Aform;

class	Intern {

	private:
		

	public:
					Intern( void );
					Intern( Intern const& src );
					Intern& operator=( Intern const& rhs );
					~Intern( void );

	AForm*			makeForm( std::string formName, std::string formTarget );

/* -------------------------------------------------------------------------- */

	class	FormNotFound : public std::exception {
		public:
			virtual const char*	what(void) const throw();
	};

};
