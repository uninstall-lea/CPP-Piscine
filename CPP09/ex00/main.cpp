#include "BitcoinExchange.hpp"


int	main(int ac, char** av) {

	BitcoinExchange rate;

	try{
	if (ac != 2)
		throw std::invalid_argument("Usage => ./btc \"infile\"");
	rate.readBtcDatabase();
	rate.readInputFile(av[1]);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}