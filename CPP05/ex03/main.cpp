#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	std::cout << "Test#1" << std::endl;
	try {
		Intern joe;
		AForm *form1;
		form1 = joe.makeForm("shrubbery creation", "garden"); 
		std::cout << *form1;
		Bureaucrat paul("Paul", 2);	
		paul.signForm(*form1);
		std::cout << *form1;
		paul.executeForm(*form1);
		delete form1;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl;
	std::cout << "Test#2" << std::endl;
	try {
		Intern joe;
		AForm *form1;
		form1 = joe.makeForm("robotomy request", "a guy"); 
		std::cout << *form1;
		Bureaucrat paul("Paul", 2);	
		paul.signForm(*form1);
		std::cout << *form1;
		paul.executeForm(*form1);
		delete form1;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl;
	std::cout << "Test#3" << std::endl;
	try {
		Intern joe;
		AForm *form1;
		form1 = joe.makeForm("presidential pardon", "bad guy"); 
		std::cout << *form1;
		Bureaucrat paul("Paul", 2);	
		paul.signForm(*form1);
		std::cout << *form1;
		paul.executeForm(*form1);
		delete form1;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl;
	std::cout << "Test#4" << std::endl;
	try {
		Intern joe;
		AForm *form1;
		form1 = joe.makeForm("whatev", "404"); 
		std::cout << *form1;
		Bureaucrat paul("Paul", 2);	
		paul.signForm(*form1);
		std::cout << *form1;
		paul.executeForm(*form1);
		delete form1;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}