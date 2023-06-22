#pragma once

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class	FragTrap : public ClapTrap {

	private:
		

	public:
					FragTrap( void );
					FragTrap ( std::string name );
					FragTrap( FragTrap const& src );
					~FragTrap( void );

		FragTrap&	operator=( FragTrap const& rhs );

		void		highFivesGuys(void);

};

