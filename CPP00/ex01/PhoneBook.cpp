#include "PhoneBook.hpp"
#include <ostream>

/* -------------------------------------------------------------------------- */
/*                           Constructor/Destructor                           */
/* -------------------------------------------------------------------------- */

PhoneBook::PhoneBook(void) {

	this->_index = 0;
	this->_isFull = false;
}

PhoneBook::~PhoneBook(void) {

	std::cout << BOLDRED "Goodbye!" RESET << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                               Adding Contacts                              */
/* -------------------------------------------------------------------------- */

/* ------------------------- Public member function ------------------------- */

int		PhoneBook::addContact() {

	std::string userInput;

	if (_index > 7)
	{
		_index = 0;
		_isFull = true;
	}

	if (!std::cin.good())
		return (FAILURE);
	this->_contacts[_index].setFirstName(userInput);

	if (!std::cin.good())
		return (FAILURE);
	this->_contacts[_index].setLastName(userInput);

	if (!std::cin.good())
		return (FAILURE);
	this->_contacts[_index].setNickname(userInput);

	if (!std::cin.good())
		return (FAILURE);
	this->_contacts[_index].setNumber(userInput);

	if (!std::cin.good())
		return (FAILURE);
	this->_contacts[_index].setDarkestSecret(userInput);

	this->_index++;

	return (SUCCESS);
}

/* -------------------------------------------------------------------------- */
/*                              Searching contacts                            */
/* -------------------------------------------------------------------------- */

/* ------------------------- Public member function ------------------------- */

int		PhoneBook::searchContact(void) {

	size_t	size;

	_isFull == true ? size = 8 : size = _index;

	if (!std::cin.good())
		return (FAILURE);

	if (_index < 1)
	{
		std::cout << "Repertoire is empty" << std::endl;
		return (SUCCESS);
	}
	_displayRepertoire(size);
	_displayContact(size);
	
	return (SUCCESS);
}

/* ------------------------ Privates member functions ----------------------- */

void		PhoneBook::_displayRepertoire(size_t size) {

	Contact		cur;

	std::cout << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		cur = _contacts[i];
		std::cout << std::right
		<< std::setw(10) << BOLDWHITE << "[" << i << "]" << RESET	<< "|"
		<< std::setw(10) << _truncate(cur.getFirstName())			<< "|"
		<< std::setw(10) << _truncate(cur.getLastName())			<< "|"
		<< std::setw(10) << _truncate(cur.getNickname())			<< "|"
		<< std::endl;
	}
	std::cout << std::endl;
}

/* -------------------------------------------------------------------------- */

void		PhoneBook::_displayContact(size_t size) {

	int			index;
	std::string	userInput;

	do
	{
		std::cout	<< "Please enter a digit between 0 and "
					<< size - 1 << " included." << std::endl;
		std::cin >> userInput;
		index = userInput[0] - '0';
		if (!std::cin.good())
			return ;

	} while (userInput[0] < '0' || userInput[0] > '7' || !isdigit(userInput[0]) || (size_t)index > size - 1);

	std::cout << std::endl;
	std::cout << "First name     : " << _contacts[index].getFirstName()		<< std::endl;
	std::cout << "Last name      : " << _contacts[index].getLastName()		<< std::endl;
	std::cout << "Nickname       : " << _contacts[index].getNickname()		<< std::endl;
	std::cout << "Number         : " << _contacts[index].getNumber()		<< std::endl;
	std::cout << "Darkest secret : " << _contacts[index].getDarkestSecret()	<< std::endl;
	std::cout << std::endl;
}

/* -------------------------------------------------------------------------- */

std::string	PhoneBook::_truncate(std::string str) {

	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}
