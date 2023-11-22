#include <iostream>
#include <cstdlib>
#include "Array.hpp"
#include "Array.tpp"

#define MAX_VAL 750
void	test1(void)
{
	std::cout << "Test 1" << std::endl;
	Array<int> test = Array<int>(2);
	std::cout << "size of array: " << test.size() << std::endl;
		for (int i = 0; i < 3; i++)
			std::cout << test[i] << std::endl;
}

void	test2(void)
{
	std::cout << std::endl;
	std::cout << "Test 2" << std::endl;
	Array<bool> test;
	std::cout << "size of array: " << test.size() << std::endl;
	std::cout << test[0] << std::endl;
}

void	test3(void)
{
	std::cout << std::endl;
	std::cout << "Test 3" << std::endl;
	Array<bool> test = Array<bool>(10);
	test[0] = true, test[9] = true;
	Array<bool> test2 = Array<bool>(test);
	for (int i = 0; i < 10; i++)
			std::cout << test2[i] << std::endl;
}

void	test4(void)
{
	std::cout << std::endl;
	std::cout << "Test 4" << std::endl;
	Array<bool> test = Array<bool>(10);
	test[0] = true, test[9] = true;
	Array<bool> test2 = test;
	for (int i = 0; i < 10; i++)
			std::cout << test2[i] << std::endl;

}

int main(void)
{
	try
	{
		test1();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		test2();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		test3();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		test4();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	
}