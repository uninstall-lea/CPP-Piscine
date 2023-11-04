#include "iter.hpp"

int	main(void) {

	int			arrayInt[] = {0, 1, 2, 3};
	std::string	arrayChar[] = {"yes", "oui", "ok", "cool"};
	bool		arrayBool[] = {true, false, true, false};

	std::cout << "Test#1" << std::endl;
	iter(arrayInt, 4, print<int>);
	std::cout << "---------" << std::endl;

	std::cout << "Test#2" << std::endl;
	iter(arrayChar, 4, print<std::string>);
	std::cout << "---------" << std::endl;

	std::cout << "Test#3" << std::endl;
	iter(arrayBool, 4, print<bool>);
	std::cout << "---------" << std::endl;

	return (0);
}