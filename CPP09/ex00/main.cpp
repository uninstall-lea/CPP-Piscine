#include "BitcoinExchange.hpp"

int main( int ac, char **av) {

	BitcoinExchange btcExchange;

	if (ac != 2)
		throw std::invalid_argument("A file is needed in argument");

	try {
		btcExchange.readBitcoinDB();
		btcExchange.readInfile(av[1]);
		std::cout << btcExchange;
	}
	catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}