#include "Bureaucrat.hpp"

void	test1(void)
{
	std::cout << "test 1" << std::endl;
	Bureaucrat	Hugo = Bureaucrat("Hugo", 0);
}

void	test2(void)
{
	std::cout << "test 2" << std::endl;
	Bureaucrat	Yoseph = Bureaucrat("Yoseph", 151);
}

void	test3(void)
{
	std::cout << "test 3" << std::endl;
	Bureaucrat	Jean = Bureaucrat("Jean", 6);

	std::cout << Jean;
	for (int i = 0; i < 6; i++)
	{
		Jean.upGrade();
		std::cout << Jean;
	}
}

void	test4(void)
{
	std::cout << "test 4" << std::endl;
	Bureaucrat	Lea = Bureaucrat("Lea", 145);

	std::cout << Lea;
	for (int i = 0; i < 6; i++)
	{
		Lea.downGrade();
		std::cout << Lea;
	}

}

int	main(void)
{
	try
	{
		test1();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		test2();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		test3();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		test4();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}