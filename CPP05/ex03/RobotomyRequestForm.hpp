#pragma once

#include <string>
#include <iostream>
#include <cstdlib>
#include "AForm.hpp"

class	RobotomyRequestForm : public AForm {

	private:
		std::string	_target;

	public:
					RobotomyRequestForm( std::string target = "Default");
					RobotomyRequestForm( RobotomyRequestForm const& src );
					RobotomyRequestForm& operator=( RobotomyRequestForm const& rhs );
					~RobotomyRequestForm( void );

	void			beExecuted( void ) const;
};