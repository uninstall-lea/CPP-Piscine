#pragma once

#include "Weapon.hpp"

class	HumanA {

	private:
		std::string		_name;
		Weapon const &	_weapon;

	public:
		HumanA( std::string name, Weapon const & weapon );
		~HumanA( void );

		void	attack( void );
};