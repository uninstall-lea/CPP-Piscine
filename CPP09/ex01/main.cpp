#include "RPN.hpp"

int main(int ac, char** av) {

	try {
		if (ac != 2)
       		throw std::invalid_argument("Usage => ./RPN \"expression\"");
		RPNCalculator::reversePolishNotation(av[1]);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
