#include "Bureaucrat.hpp"

/* -------------------------------------------------------------------------- */
/*                          Constructor / Destructor                          */
/* -------------------------------------------------------------------------- */

Bureaucrat::Bureaucrat( void ) : _name("noName"), _grade(150) {

}

Bureaucrat::Bureaucrat (std::string name, int grade ) {

	if (verifyAccess(grade) == "Not Granted")
		return;

	_name = name;
	_grade = grade;
}

Bureaucrat::Bureaucrat( Bureaucrat const& src ) {

	if (verifyAccess(src._grade) == "Granted")
		*this = src;
}

Bureaucrat&	Bureaucrat::operator=( Bureaucrat const& rhs ) {
	
	if (verifyAccess(rhs._grade) == "Not Granted")
		return (*this);

	_name = rhs.getName();
	_grade = rhs.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat( void ) {

}

/* -------------------------------------------------------------------------- */
/*                                  Functions                                 */
/* -------------------------------------------------------------------------- */

std::string const&	Bureaucrat::getName( void ) const {

	return (_name);
}

int const&	Bureaucrat::getGrade( void ) const {

	return (_grade);
}

std::string	Bureaucrat::verifyAccess( int const& grade ) {

	if ( grade < 1 )
		throw Bureaucrat::GradeTooHighExecption();
	else if ( grade > 150 )
		throw Bureaucrat::GradeTooLowException();
	else
		return ("Granted");
	return ("Not Granted");
}

void	Bureaucrat::upGrade(void) {

	if (verifyAccess(_grade - 1) == "Granted")
		_grade--;
}

void	Bureaucrat::downGrade(void) {
	if (verifyAccess(_grade + 1) == "Granted")
		_grade++;
}

/* -------------------------------------------------------------------------- */
/*                                 Exceptions                                 */
/* -------------------------------------------------------------------------- */

const char*	Bureaucrat::GradeTooHighExecption::what( void ) const throw() {

	return ("Bureaucrat grade is too high !");
}

const char*	Bureaucrat::GradeTooLowException::what( void ) const throw() {

	return ("Bureaucrat grade is too low !");
}

/* -------------------------------------------------------------------------- */
/*                                   Ostream                                  */
/* -------------------------------------------------------------------------- */

std::ostream&	operator<<(std::ostream& out, Bureaucrat const & rhs) {

	out	<< rhs.getName() << ", bureaucrat grade " 
		<< rhs.getGrade() << "." << std::endl;
	return (out);
}