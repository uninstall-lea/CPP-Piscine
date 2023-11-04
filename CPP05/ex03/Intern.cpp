#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

std::string formID[4] = { "shrubbery creation", "presidential pardon", "robotomy request" };

Intern::Intern( void ) {

}

Intern::Intern( Intern const& src ) {

	*this = src;
}

Intern::~Intern( void ) {

}

Intern&	Intern::operator=( Intern const& rhs ) {

	(void) rhs;
	return (*this);
}

AForm* Intern::makeForm( std::string formName, std::string formTarget ) {

	size_t ID = 0;

	while (formID[ID] != formName && ID < 3)
		ID++;

	if (ID == 3)
		throw FormNotFound();

	else {
		std::cout << "Intern creates " << formName << std::endl;
		switch (ID) {
			case 0:
				return (new ShrubberyCreationForm(formTarget));
			case 1:
				return (new PresidentialPardonForm(formTarget));
			case 2:
				return (new RobotomyRequestForm(formTarget));
		}
	}
	return (NULL);
}

const char*	Intern::FormNotFound::what( void ) const throw() {

	return ("Form not found in database!");
}