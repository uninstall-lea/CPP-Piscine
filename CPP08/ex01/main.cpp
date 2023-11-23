#include "Span.hpp"

int	main(void)
{
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);// 3 -> 14 longest
		sp.addNumber(17);
		sp.addNumber(9);// 9 -> 11 smallest
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::vector <int> vect;
	for (int i = 0; i < 25000; i++)
	{
		vect.push_back(i);
	}
	try {
		Span test = Span(25000);
		test.addNumber(vect);
		std::cout << test.shortestSpan() << std::endl;// 1 -> 2
		std::cout << test.longestSpan() << std::endl;// 1 -> 24500
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
