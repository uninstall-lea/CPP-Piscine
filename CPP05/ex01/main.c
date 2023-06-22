#include "Bureaucrat.hpp"
#include "Form.hpp"

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

void	test5(void)
{
	std::cout << "test 5" << std::endl;
	Form	test = Form("test", 0, 0);
}

void	test6(void)
{
	std::cout << "test 6" << std::endl;
	Form	test = Form("test", 151, 151);
}

void	test7(void)
{
	std::cout << "test 7" << std::endl;
	Form 		mairie = Form("mairie", 50, 10);
	Bureaucrat	jean = Bureaucrat("Jean", 5);
	Bureaucrat	jacques = Bureaucrat("Jacques", 100);

	std::cout << mairie;
	std::cout << jean;
	std::cout << jacques;

	jacques.signForm(mairie);
	jean.signForm(mairie);
	jean.signForm(mairie);

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
	std::cout << std::endl;

	try
	{
		test5();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		test6();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		test7();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

}