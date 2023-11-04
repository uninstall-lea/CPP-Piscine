#pragma once

#include <string>
#include <iostream>
#include "AForm.hpp"

class	RobotomyRequestForm : public AForm {

	private:
		std::string	_target;
		void		execute( Bureaucrat const& executor ) const;

	public:
					// RobotomyRequestForm( void );
					RobotomyRequestForm( std::string target );
					RobotomyRequestForm( RobotomyRequestForm const& src );
					RobotomyRequestForm& operator=( RobotomyRequestForm const& rhs );
					~RobotomyRequestForm( void );
};