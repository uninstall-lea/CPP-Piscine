#pragma once

#include <string>
#include <iostream>
#include "AForm.hpp"

#define TREE "\
		 /\\\n\
        /  \\\n\
       /    \\\n\
      / +    \\\n\
     /     ¤  \\\n\
    /__     *__\\\n\
      /  +   \\\n\
     / *      \\\n\
    /     *    \\\n\
   /  +    ¤    \\\n\
  /___        ___\\\n\
     /     *  \\\n\
    /  *       \\\n\
   /         +  \\\n\
  / +            \\\n\
 /         *      \\\n\
/__________________\\\n\
        |  |\n\
        |  |\n\
        |  |\n\
        ====\n"


class	ShrubberyCreationForm : public AForm {

	private:
		std::string	_target;

	public:
					ShrubberyCreationForm( std::string target = "Default" );
					ShrubberyCreationForm( ShrubberyCreationForm const& src );
					ShrubberyCreationForm& operator=( ShrubberyCreationForm const& rhs );
					~ShrubberyCreationForm( void );

	void			beExecuted( void ) const;

/* -------------------------------------------------------------------------- */

	class	ErrorOpeningFile : public std::exception {
		public:
			virtual const char 	*what() const throw() {
				return ("Error in the process of opening the file");
			}
	};
};
