#include "PhoneBook.hpp"

int main(void) {

	PhoneBook	repertoire;
	std::string	userInput;

	std::cout << BOLDGREEN "\nWelcome to the PhoneBook !\n" RESET << std::endl;
	std::cout << "Please enter a command such as: ";
	std::cout << BOLDYELLOW "'ADD', 'SEARCH' or 'EXIT'" RESET << std::endl;

	while (std::cin.good())
	{

		std::getline(std::cin, userInput);

		if (userInput == "ADD")
		{
			if (repertoire.addContact() == FAILURE)
				return (FAILURE);
			std::cout << "Please enter a command such as: ";
			std::cout << BOLDYELLOW "'ADD', 'SEARCH' or 'EXIT'" RESET << std::endl;
		}

		else if (userInput == "SEARCH")
		{
			if (repertoire.searchContact() == FAILURE)
				return (FAILURE);
			std::cout << "Please enter a command such as: ";
			std::cout << BOLDYELLOW "'ADD', 'SEARCH' or 'EXIT'" RESET << std::endl;
		}

		else if (userInput == "EXIT")
			return (SUCCESS);

	}

	return (0);
}