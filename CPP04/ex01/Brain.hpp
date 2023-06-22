#pragma once

#include <string>
#include <iostream>

class	Brain {

	protected:
		std::string	ideas[100];	

	public:
				Brain( void );
				Brain( Brain const& src );
				~Brain( void );

		Brain&	operator=( Brain const& rhs );

};