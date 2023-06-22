#pragma once

#include <string>
#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap {

	private:
		std::string		_name;

	public:
						DiamondTrap( void );
						DiamondTrap( std::string name );
						DiamondTrap( DiamondTrap const& src );
						~DiamondTrap( void );

		DiamondTrap&	operator=( DiamondTrap const& rhs );

		void 			whoAmI( void );
		void			attack( std::string const& target );

};
