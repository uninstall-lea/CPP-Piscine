#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << "Test#1" << std::endl;
	try {
		Form form1("form1", 2, 3);
		std::cout << form1;
		Bureaucrat paul("Paul", 2);	
		std::cout << paul;
		paul.signForm(form1);
		std::cout << form1;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << std::endl;
	std::cout << "Test#2" << std::endl;
	try {
		Form form1("form1", 1, 3);
		std::cout << form1;
		Bureaucrat paul("Paul", 2);	
		std::cout << paul;
		paul.signForm(form1);
		std::cout << form1;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl;
	std::cout << "Test#3" << std::endl;
	try {
		Form form1("form1", -1, 3);
		std::cout << form1;
		Bureaucrat paul("Paul", 2);
		std::cout << paul;
		paul.signForm(form1);
		std::cout << form1;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl;
	std::cout << "Test#4" << std::endl;
	try {
		Form form1("form1", 1, -3);
		std::cout << form1;
		Bureaucrat paul("Paul", 2);
		std::cout << paul;
		paul.signForm(form1);
		std::cout << form1;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl;
	std::cout << "Test#5" << std::endl;
	try {
		Form form1("form1", 1, 151);
		std::cout << form1;
		Bureaucrat paul("Paul", 2);
		std::cout << paul;
		paul.signForm(form1);
		std::cout << form1;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl;
	std::cout << "Test#6" << std::endl;
	try {
		Form form1("form1", 151, 2);
		std::cout << form1;
		Bureaucrat paul("Paul", 2);
		std::cout << paul;
		paul.signForm(form1);
		std::cout << form1;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}