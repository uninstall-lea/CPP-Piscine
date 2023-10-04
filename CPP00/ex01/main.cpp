#include "PhoneBook.hpp"

int main(void) {

	PhoneBook	repertoire;
	std::string	userInput;

	std::cout << BOLDGREEN "\nWelcome to the PhoneBook !\n" RESET << std::endl;

	while (42) {
		do {
			std::cout << "Please enter a command such as: ";
			std::cout << BOLDYELLOW "'ADD', 'SEARCH' or 'EXIT'" RESET << std::endl;
			std::getline(std::cin, userInput);
		}
		while (std::cin.good()
				&& userInput != "ADD" && userInput != "SEARCH" && userInput != "EXIT");

		if (userInput == "ADD")
		{
			if (repertoire.addContact() == FAILURE)
				return (FAILURE);
		}

		else if (userInput == "SEARCH")
		{
			if (repertoire.searchContact() == FAILURE)
				return (FAILURE);
		}

		else if (userInput == "EXIT")
			return (SUCCESS);
	}

	return (0);
}