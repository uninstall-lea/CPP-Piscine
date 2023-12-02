#include "BitcoinExchange.hpp"


int	main(int ac, char** av) {

	BitcoinExchange rate;

	if (ac != 2)
		throw std::invalid_argument("Usage => ./btc \"infile\"");
	rate.readBtcDatabase();
	rate.readInputFile(av[1]);

	return (EXIT_SUCCESS);
}