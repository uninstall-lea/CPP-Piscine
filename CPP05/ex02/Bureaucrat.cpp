#include "Bureaucrat.hpp"

/* -------------------------------------------------------------------------- */
/*                          Constructor / Destructor                          */
/* -------------------------------------------------------------------------- */

Bureaucrat::Bureaucrat( void ) : _name("noName"), _grade(150) {

}

Bureaucrat::Bureaucrat (std::string name, int grade ) : _name(name) {

	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
	
}

Bureaucrat::Bureaucrat( Bureaucrat const& src ) : _name(src.getName()) {

	if (src.getGrade() < 1)
		throw GradeTooHighException();
	else if (src.getGrade() > 150)
		throw GradeTooLowException();
	else
		*this = src;
}

Bureaucrat&	Bureaucrat::operator=( Bureaucrat const& rhs ) {
	
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


void	Bureaucrat::upGrade(void) {

	if (_grade == 1)
		throw GradeTooHighException();
	else
		_grade--;
}

void	Bureaucrat::downGrade(void) {

	if (_grade == 150)
		throw GradeTooLowException();
	else
		_grade++;
}

void	Bureaucrat::signForm( AForm& form ) {

	try {
		form.beSigned(*this);
		std::cout	<< "Bureaucrat " << _name
					<< " signed form " << form.getName() << std::endl;
	}
	catch (std::exception& e) {
		std::cout	<< "Bureaucrat " << _name
					<< " could not sign form because his grade is too low" << std::endl;
	}
}

void	Bureaucrat::executeForm( AForm const& form ) {

	try
	 {
		form.execute(*this);
		std::cout	<< "Bureaucrat " << _name
					<< " executed form " << form.getName() << std::endl;
	}
	catch (std::exception& e) {
		std::cout	<< "Bureaucrat " << _name
					<< " could not execute form: " << e.what() << std::endl;
	}
}


/* -------------------------------------------------------------------------- */
/*                                 Exceptions                                 */
/* -------------------------------------------------------------------------- */

const char*	Bureaucrat::GradeTooHighException::what( void ) const throw() {

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