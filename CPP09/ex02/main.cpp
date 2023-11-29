#include "PmergeMe.hpp"

int main(int ac, char** av) {

	try {

		if (ac < 2)
        	std::invalid_argument("Error => No input sequence provided.");

		PmergeMe::run(ac, av);
    }
	catch (std::exception& e) {

		std::cerr << e.what() << std::endl;
		return (EXIT_FAILURE);
	}

    return (EXIT_SUCCESS);
}
