#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	std::cout << "Test#1" << std::endl;
	try {
		ShrubberyCreationForm form1("form1");
		std::cout << form1;
		Bureaucrat paul("Paul", 2);	
		paul.signForm(form1);
		std::cout << form1;
		paul.executeForm(form1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << std::endl;
	std::cout << "Test#2" << std::endl;
	try {
		ShrubberyCreationForm form1("form1");
		std::cout << form1;
		Bureaucrat paul("Paul", 146);	
		paul.signForm(form1);
		std::cout << form1;
		paul.executeForm(form1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl;
	std::cout << "Test#3" << std::endl;
	try {
		ShrubberyCreationForm form1("form1");
		std::cout << form1;
		Bureaucrat paul("Paul", 138);	
		paul.signForm(form1);
		std::cout << form1;
		paul.executeForm(form1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl;
	std::cout << "Test#4" << std::endl;
	try {
		RobotomyRequestForm form1("form1");
		std::cout << form1;
		Bureaucrat paul("Paul", 2);	
		paul.signForm(form1);
		std::cout << form1;
		paul.executeForm(form1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl;
	std::cout << "Test#5" << std::endl;
	try {
		PresidentialPardonForm form1("form1");
		std::cout << form1;
		Bureaucrat paul("Paul", 2);	
		paul.signForm(form1);
		std::cout << form1;
		paul.executeForm(form1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}