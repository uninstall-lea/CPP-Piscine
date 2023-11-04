#pragma once

#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class	AForm {

	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_signGrade;
		int	const			_execGrade;
		virtual void		execute( Bureaucrat const& executor ) const = 0;


	public:
							AForm( void );
							AForm ( std::string name, int signGrade, int execGrade );
							AForm( AForm const& src );
							AForm& operator=( AForm const& rhs );
	virtual					~AForm( void );

	std::string const&		getName( void ) const;
	bool const&				getStatus( void ) const;
	int const&				getSignGrade( void ) const;
	int const&				getExecGrade( void ) const;

	void					beSigned( Bureaucrat const& src );

/* ------------------------------- Exceptions ------------------------------- */

		class	GradeTooHighException : public std::exception {
			public:
				virtual const char*	what(void) const throw();
		};

		class	GradeTooLowException : public std::exception {
			public:
				virtual const char*	what(void) const throw();
		};

		class	AlreadySignException : public std::exception {
			public:
				virtual const char*	what(void) const throw();
		};

		class	FormNotSigned : public std::exception {
			public:
				virtual const char*	what(void) const throw();
		};

};

std::ostream&	operator<<(std::ostream& out, AForm const & rhs);
