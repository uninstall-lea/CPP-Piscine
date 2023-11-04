#include "Form.hpp"

/* -------------------------------------------------------------------------- */
/*                          Constructor / Destructor                          */
/* -------------------------------------------------------------------------- */

Form::Form( void )
	: _name("noName"), _isSigned(false), _signGrade(150), _execGrade(150) {

}

Form::Form ( std::string name, int signGrade, int execGrade )
	: _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {

	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

Form::Form( Form const& src )
	: _name(src.getName()), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade()) {

	if (src.getSignGrade() < 1 || src.getExecGrade() < 1)
		throw GradeTooHighException();
	else if (src.getSignGrade() > 150 || src.getExecGrade() > 150)
		throw GradeTooLowException();
	else
		*this = src;
}

Form&	Form::operator=( Form const& rhs ) {

	_isSigned = rhs.getStatus();
	return (*this);
}

Form::~Form( void ) {

}

/* -------------------------------------------------------------------------- */
/*                                  Functions                                 */
/* -------------------------------------------------------------------------- */

std::string const&	Form::getName( void ) const {

	return (_name);
}

bool const&	Form::getStatus( void ) const {

	return (_isSigned);
}

int const&	Form::getSignGrade( void ) const {

	return (_signGrade);
}

int const&	Form::getExecGrade( void ) const {

	return (_execGrade);
}

void	Form::beSigned( Bureaucrat const& src ) {

	if (getStatus() == true)
		throw AlreadySignException();

	else if (src.getGrade() > getSignGrade())
		throw GradeTooLowException();

	else
		_isSigned = true;
}

/* -------------------------------------------------------------------------- */
/*                                 Exceptions                                 */
/* -------------------------------------------------------------------------- */

const char*	Form::GradeTooHighException::what( void ) const throw() {

	return ("Form grade is too high!");
}

const char*	Form::GradeTooLowException::what( void ) const throw() {

	return ("Form grade is too low!");
}

const char*	Form::AlreadySignException::what( void ) const throw() {

	return ("This form is already signed !");
}

/* -------------------------------------------------------------------------- */
/*                                   Ostream                                  */
/* -------------------------------------------------------------------------- */

std::ostream&	operator<<(std::ostream& out, Form const & rhs)
{
	std::string	status;

	if (rhs.getStatus() == true)
		status = "Signed";
	else
		status = "Not signed";

	out	<< std::left
		<< std::setw(15) << "NAME"				<< "|"
		<< std::setw(15) << "STATUS"			<< "|"
		<< std::setw(15) << "TO SIGN"			<< "|"
		<< std::setw(15) << "TO EXEC"			<< "|"
		<< std::endl;
	
	out	<< std::left
		<< std::setw(15) << rhs.getName()		<< "|"
		<< std::setw(15) << status				<< "|"
		<< std::setw(15) << rhs.getSignGrade()	<< "|"
		<< std::setw(15) << rhs.getExecGrade()	<< "|"
		<< std::endl << std::endl;

	return (out);
}
