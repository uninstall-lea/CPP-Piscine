#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "Test#1" << std::endl;
	try {
		Bureaucrat paul("Paul", -1);	
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << std::endl;
	std::cout << "Test#2" << std::endl;
	try {
		Bureaucrat paul("Paul", 151);	
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << std::endl;
	std::cout << "Test#3" << std::endl;
	try {
		Bureaucrat paul("Paul", 150);
		std::cout << paul;
		paul.downGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl;
	std::cout << "Test#4" << std::endl;
	try {
		Bureaucrat paul("Paul", 1);
		std::cout << paul;
		paul.upGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << std::endl;
	std::cout << "Test#5" << std::endl;
	try {
		Bureaucrat paul("Paul", 5);
		std::cout << paul;
		paul.upGrade();
		std::cout << paul;
		paul.upGrade();
		std::cout << paul;
		paul.upGrade();
		std::cout << paul;
		paul.downGrade();
		std::cout << paul;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}