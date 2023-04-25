#pragma once

# include <string>

class Contact {
	
	private:
		std::string 		_firstName;
		std::string 		_lastName;
		std::string 		_nickname;
		std::string			_number;
		std::string 		_darkestSecret;

	public:
		Contact();
		~Contact();

		/* Getter */
		const std::string&	getFirstName(void) const;
		const std::string&	getLastName(void) const;
		const std::string&	getNickname(void) const;
		const std::string&	getNumber(void) const;
		const std::string&	getDarkestSecret(void) const;
		
		/* Setter */
		void				setFirstName(std::string);
		void				setLastName(std::string);
		void				setNickname(std::string);
		void				setNumber(std::string);
		void				setDarkestSecret(std::string);
};
