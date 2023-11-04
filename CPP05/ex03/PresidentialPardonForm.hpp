#pragma once

#include <string>
#include <iostream>
#include "AForm.hpp"

class	PresidentialPardonForm : public AForm {

	private:
		std::string	_target;

	public:
					PresidentialPardonForm( std::string target = "Default");
					PresidentialPardonForm( PresidentialPardonForm const& src );
					PresidentialPardonForm& operator=( PresidentialPardonForm const& rhs );
					~PresidentialPardonForm( void );

	void			beExecuted( void ) const;

};