#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( std::string target )
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {

}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const& src )
	: AForm(src.getName(), src.getSignGrade(), src.getExecGrade()), _target(src._target) {

	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {

}

RobotomyRequestForm&	RobotomyRequestForm::operator=( RobotomyRequestForm const& rhs ) {

	(void) rhs;
	return (*this);
}

/*----------------------------------------------------------------------------*/

void	RobotomyRequestForm::beExecuted( void ) const {

	static int	init = 0;

	std::cout << "* DzzzZzzzZZzDzzzzzZZZz *" << std::endl;
	if (init++ == 0)
		srand(time(0));
	if (rand() % 2)
		std::cout << _target << " has been successfully robotimized" << std::endl;
	else
		std::cout << _target << " failed to be robotomized" << std::endl;
}