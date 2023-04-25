#include "PhoneBook.hpp"
#include <ostream>

/* -------------------------------------------------------------------------- */
/*                           Constructor/Destructor                           */
/* -------------------------------------------------------------------------- */

PhoneBook::PhoneBook(void) {

	this->_index = 0;
	this->_status = 0;
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

	if (_index > 8)
		_index = 0;

	if (this->_status == FAILURE)
		return (FAILURE);
	userInput = _returnValidInfo("Please enter your first name: ");
	this->_contacts[_index].setFirstName(userInput);

	if (this->_status == FAILURE)
		return (FAILURE);
	userInput = _returnValidInfo("Please enter your last name: ");
	this->_contacts[_index].setLastName(userInput);

	if (this->_status == FAILURE)
		return (FAILURE);
	userInput = _returnValidInfo("Please enter your nickname: ");
	this->_contacts[_index].setNickname(userInput);

	if (this->_status == FAILURE)
		return (FAILURE);
	userInput = _returnValidNumber("Please enter your number: ");
	this->_contacts[_index].setNumber(userInput);

	if (this->_status == FAILURE)
		return (FAILURE);
	userInput = _returnValidInfo("Please enter your darkest secret: ");
	this->_contacts[_index].setDarkestSecret(userInput);

	this->_index++;

	return (SUCCESS);
}

/* ------------------------ Privates member functions ----------------------- */

std::string	PhoneBook::_returnValidInfo(std::string message) {

	std::string userInput;

	if (!std::cin.good())
		this->_status = FAILURE;

	do
	{
		std::cout << message << std::endl;
		std::cin >> userInput;

	} while (userInput.length() == 0);

	return (userInput);
}

/* -------------------------------------------------------------------------- */

std::string	PhoneBook::_returnValidNumber(std::string message) {
	
	bool		isDigit;
	std::string userInput;

	do
	{
		isDigit = true;
		std::cout << message << std::endl;
		std::cin >> userInput;

		for(std::string::iterator it = userInput.begin(); it != userInput.end(); it++)
			if (!isdigit(*it))
				isDigit = false;
	
	} while (isDigit == false);

	return (userInput);
}

/* -------------------------------------------------------------------------- */
/*                              Searching contacts                            */
/* -------------------------------------------------------------------------- */

/* ------------------------- Public member function ------------------------- */

int		PhoneBook::searchContact(void) {

	if (_index < 1)
	{
		std::cout << "Repertoire is empty" << std::endl;
		return (SUCCESS);
	}
	
	_displayRepertoire();
	_displayContact();

	return (SUCCESS);
}

/* ------------------------ Privates member functions ----------------------- */

void		PhoneBook::_displayRepertoire(void) {

	Contact		cur;

	std::cout << std::endl;
	for (size_t i = 0; i < _index; i++)
	{
		cur = _contacts[i];
		std::cout << std::right
		<< BOLDWHITE << "[" << i <<"]" << RESET 				<< "|"
		<< std::setw(10) << _truncate(cur.getFirstName()) 		<< "|"
		<< std::setw(10) << _truncate(cur.getLastName()) 		<< "|"
		<< std::setw(10) << _truncate(cur.getNickname()) 		<< "|"
		<< std::setw(10) << _truncate(cur.getNumber())			<< "|"
		<< std::setw(10) << _truncate(cur.getDarkestSecret())	<< "|"
		<< std::endl;
	}
	std::cout << std::endl;
}

/* -------------------------------------------------------------------------- */

void		PhoneBook::_displayContact(void) {

	int			index;
	std::string	userInput;

	do
	{
		std::cout	<< "Please enter a digit between 0 or "
					<< this->_index - 1 << " included." << std::endl;
		std::cin >> userInput;
		index = userInput[0] - '0';

	} while (userInput[0] < '0' || userInput[0] > '8' || userInput.length() != 1
			||!isdigit(userInput[0]) || (size_t)index > this->_index);
	
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
