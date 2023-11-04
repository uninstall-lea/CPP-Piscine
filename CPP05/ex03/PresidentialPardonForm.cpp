#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( std::string target )
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {

}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const& src )
	: AForm(src.getName(), src.getSignGrade(), src.getExecGrade()), _target(src._target) {

	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {

}

PresidentialPardonForm&	PresidentialPardonForm::operator=( PresidentialPardonForm const& rhs ) {

	(void) rhs;
	return (*this);
}

/*----------------------------------------------------------------------------*/

void	PresidentialPardonForm::beExecuted( void ) const {

	std::cout << _target << " has been pardoned by our good president Zaphod Beeblerox" << std::endl;
}