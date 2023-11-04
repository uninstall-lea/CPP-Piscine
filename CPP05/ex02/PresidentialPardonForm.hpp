#pragma once

#include <string>
#include <iostream>
#include "AForm.hpp"

class	PresidentialPardonForm : public AForm {

	private:
		std::string	_target;
		void		execute( Bureaucrat const& executor ) const;

	public:
					PresidentialPardonForm( std::string target );
					PresidentialPardonForm( PresidentialPardonForm const& src );
					PresidentialPardonForm& operator=( PresidentialPardonForm const& rhs );
					~PresidentialPardonForm( void );
};