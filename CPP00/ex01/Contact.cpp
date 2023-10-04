#include "Contact.hpp"

Contact::Contact(void) {

}

Contact::~Contact(void) {

}

const std::string&	Contact::getFirstName(void) const {

	return (this->_firstName);
}

const std::string&	Contact::getLastName(void) const {

	return (this->_lastName);
}

const std::string&	Contact::getNickname(void) const {

	return (this->_nickname);
}

const std::string&	Contact::getNumber(void) const {

	return (this->_number);
}

const std::string&	Contact::getDarkestSecret(void) const {

	return (this->_darkestSecret);
}

void				Contact::setFirstName(std::string userInput) {

	userInput = _returnValidInfo("Please enter your first name: ");
	this->_firstName = userInput;
}

void				Contact::setLastName(std::string userInput) {


	userInput = _returnValidInfo("Please enter your last name: ");
	this->_lastName = userInput;
}

void				Contact::setNickname(std::string userInput) {

	userInput = _returnValidInfo("Please enter your nickname: ");
	this->_nickname = userInput;
}

void				Contact::setNumber(std::string userInput) {

	userInput = _returnValidNumber("Please enter your number: ");
	this->_number = userInput;
}

void				Contact::setDarkestSecret(std::string userInput) {

	userInput = _returnValidInfo("Please enter your darkest secret: ");
	this->_darkestSecret = userInput;
}

/* -------------------------------------------------------------------------- */


std::string	Contact::_returnValidInfo(std::string message) {

	std::string userInput;

		std::cout << message << std::endl;
	do
		std::getline(std::cin, userInput);
	while (userInput.length() == 0 && std::cin.good());

	return (userInput);
}

std::string	Contact::_returnValidNumber(std::string message) {
	
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