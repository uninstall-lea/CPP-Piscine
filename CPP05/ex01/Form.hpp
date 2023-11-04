#pragma once

#include <string>
#include <iomanip>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class	Form {

	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_signGrade;
		int	const			_execGrade;

	public:
							Form( void );
							Form ( std::string name, int signGrade, int execGrade );
							Form( Form const& src );
							Form& operator=( Form const& rhs );
							~Form( void );

	std::string const&		getName( void ) const;
	bool const&				getIsSigned( void ) const;
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

};

std::ostream&	operator<<(std::ostream& out, Form const & rhs);
