#include "BitcoinExchange.hpp"

int main( int ac, char **av) {

	BitcoinExchange btcExchg;

	try {
		if (ac != 2)
			throw std::invalid_argument("A file is needed in argument");
		btcExchg.checkBtcFile();
		btcExchg.checkInfile(av[1]);
	}
	catch (std::exception const& e) {
		std::cerr << e.what() << std::endl;
		return (EXIT_FAILURE);
	}

	std::ifstream btcFile("data.csv");
	std::ifstream inFile(av[1]);

	btcExchg.readBtcFile(btcFile);
	btcExchg.readInFile(inFile);
	std::cout << btcExchg;

	btcFile.close(), inFile.close();

	return (EXIT_SUCCESS);
}

/* -------------------------------------------------------------------------- */
/*                             Non members methods                            */
/* -------------------------------------------------------------------------- */
/* -------------------------------- * Utils * ------------------------------- */
size_t	separatorPos( std::string const& line, std::string const& sep) {

	size_t	pos = line.find(sep.c_str());

	if (pos == std::string::npos)
		throw std::invalid_argument("Bad format in file: separator not found: '" + sep + "\'");
	return (pos);
};

std::string trimSpaces( std::string line, bool part ) {

	std::string		trimmed;
	size_t			pos = separatorPos(line, "|");

	if (part == isDate)
		trimmed = line.substr(0, pos - 1); // Before '|'
	else //isValue
		trimmed = line.substr(0, pos + 1); // After '|'

	trimmed.erase(std::remove(trimmed.begin(), trimmed.end(), ' '), trimmed.end());

	return (trimmed);
}
/* -------------------------- * Output formating * -------------------------- */

std::ostream& operator<<(std::ostream& out, BitcoinExchange const& rhs) {

	rhs.outFormat(out);
	return (out);
};