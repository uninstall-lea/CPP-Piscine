#include "BitcoinExchange.hpp"

int main( int ac, char **av) {

	try {
		BitcoinExchange btcExchg;

		if (ac != 2)
			throw std::invalid_argument("A file is needed in argument");
		checkBtcFile();
		checkInfile(av[1]);

		std::ifstream btcFile("data.csv");
		std::ifstream inFile(av[1]);
		btcExchg.readBtcFile(btcFile);
		btcExchg.readInFile(inFile);
		std::cout << btcExchg;
		btcFile.close(), inFile.close();
	}
	catch (std::exception const& e) {
		std::cerr << e.what() << std::endl;
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}

/* -------------------------------------------------------------------------- */
/*                             Non members methods                            */
/* -------------------------------------------------------------------------- */
/* --------------------------- * Checking files * --------------------------- */
void	checkBtcFile( void ) {

	std::string		line;
	std::ifstream	btcFile("data.csv");

	if (!btcFile.is_open())
		btcFile.close(), throw std::runtime_error("Could not open 'data.csv'");

	getline(btcFile, line);
	if (btcFile.eof())
		btcFile.close(), throw std::runtime_error("File is empty");

	if (line  != "date,exchange_rate")
		btcFile.close(), throw std::invalid_argument("Bad format in file: 'date,exchange_rate' expected");

}

void	checkInfile( std::string const& filename ) {

	std::string 	line;
	std::ifstream	inFile(filename.c_str());

	if (!inFile.is_open())
		inFile.close(), throw std::runtime_error("Could not open input file: '" + filename + "\'");

	getline(inFile, line);
	if (inFile.eof())
		inFile.close(), throw std::runtime_error("File is empty");

}
/* -------------------------------- * Utils * ------------------------------- */
size_t	separatorPos( std::string const& line, std::string const& sep) {

	size_t	pos = line.find(sep.c_str());

	// if we reach the end after the first find, then there is no separator
	if (pos == std::string::npos)
		throw std::invalid_argument("Bad format in file: separator not found: '" + sep + "\'");

	// if we did not reach the end of line with second find(), then there is more than one separator
	if (line.find(sep, pos + sep.size()) != std::string::npos)
        throw std::invalid_argument("Bad format in file: more than one separator: '" + sep + "'");

	return (pos);
};

std::string trimSpaces( std::string line, std::string sep, bool part ) {

	std::string		trimmed;
	size_t			pos = separatorPos(line, sep);

	if (part == isDate)
		trimmed = line.substr(0, pos - 1); // Before '|'
	else //isValue
		trimmed = line.substr(pos); // No + something because we trimmed all spaces

	trimmed.erase(std::remove(trimmed.begin(), trimmed.end(), ' '), trimmed.end());

	return (trimmed);
}
/* -------------------------- * Output formating * -------------------------- */

std::ostream& operator<<(std::ostream& out, BitcoinExchange const& rhs) {

	rhs.outFormat(out);
	return (out);
};