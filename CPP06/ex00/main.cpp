#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		std::string str(av[1]);
		ScalarConverter::print(str);
	}
	else
		std::cout << "Wrong number of arguments {1 required}" << std::endl;
}