#pragma once

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class	ScavTrap : public virtual ClapTrap {

	private:
		

	public:
					ScavTrap( void );
					ScavTrap( std::string name );
					ScavTrap( ScavTrap const& src );
					~ScavTrap( void );

		ScavTrap&	operator=( ScavTrap const& rhs );

		void 		guardGate( void );
		void		attack( std::string const& target );

};
