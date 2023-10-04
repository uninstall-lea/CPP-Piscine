#pragma once

# include "Contact.hpp"
# include <iostream>
# include <iomanip>
# include <ostream>
# include <cstdlib>

# define SUCCESS	0
# define FAILURE	1

# define RESET		"\033[0m"
# define BOLDWHITE	"\033[1;37m"
# define BOLDRED	"\033[1;31m"
# define BOLDGREEN	"\033[1;32m"
# define BOLDYELLOW	"\033[1;33m"

class PhoneBook {
	
	private:
		bool		_isFull;
		size_t		_index;
		Contact 	_contacts[8];

		void		_displayContact(size_t);
		void		_displayRepertoire(size_t);

		std::string	_truncate(std::string);
		std::string	_returnValidNumber(std::string);

	public:
		PhoneBook();
		~PhoneBook();

		int 		addContact(void);
		int			searchContact(void);
};
