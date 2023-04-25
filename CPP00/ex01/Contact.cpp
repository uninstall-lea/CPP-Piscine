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

void				Contact::setFirstName(std::string str) {
	
	this->_firstName = str;
}

void				Contact::setLastName(std::string str) {
	
	this->_lastName = str;
}

void				Contact::setNickname(std::string str) {
	
	this->_nickname = str;
}

void				Contact::setNumber(std::string str) {
	this->_number = str;
}

void				Contact::setDarkestSecret(std::string str) {
	
	this->_darkestSecret = str;
}