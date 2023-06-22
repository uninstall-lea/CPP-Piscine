#pragma once

#include <string>
#include <iostream>
#include "Form.hpp"

class	ShrubberyCreationForm : public Form {

	private:
		std::string	_target;

	public:
					ShrubberyCreationForm( std::string target );
					ShrubberyCreationForm( ShrubberyCreationForm const& src );
					ShrubberyCreationForm& operator=( ShrubberyCreationForm const& rhs );
					~ShrubberyCreationForm( void );

	void			execute( Bureaucrat const& executor ) const;

};

/*----------------------------------------------------------------------------*/

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) {

}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const& src ) {

	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {

}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=( ShrubberyCreationForm const& rhs ) {

	return (*this);
}

/*----------------------------------------------------------------------------*/
