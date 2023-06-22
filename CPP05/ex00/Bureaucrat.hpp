#pragma once

#include <string>
#include <iostream>
#include <exception>

class	Bureaucrat {

	private:
		std::string			_name;
		int					_grade;


	public:
							Bureaucrat( void );
							Bureaucrat( Bureaucrat const& src );
							Bureaucrat ( std::string name, int grade );
							Bureaucrat&	operator=( Bureaucrat const& rhs );
							~Bureaucrat( void );

		std::string const&	getName( void ) const;
		int const&			getGrade( void ) const;

		std::string			verifyAccess( int const& grade );
		void				upGrade(void);
		void				downGrade(void);

/* ------------------------------- Exceptions ------------------------------- */

		class	GradeTooHighExecption : public std::exception {
			public:
				virtual const char*	what( void ) const throw();
		};

		class	GradeTooLowException : public std::exception {
			public:
				virtual const char*	what( void ) const throw();
		};
};

std::ostream&	operator<<(std::ostream& out, Bureaucrat const & rhs);