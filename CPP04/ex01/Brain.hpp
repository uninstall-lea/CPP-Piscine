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

		std::string const&	getIdea( int idx ) const;
		void				setIdea( int idx, std::string newIdea );

		Brain&				operator=( Brain const& rhs );

};