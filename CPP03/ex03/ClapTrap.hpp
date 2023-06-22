#pragma once

#include <string>
#include <iostream>

class	ClapTrap {

	protected:
		std::string _name;
		int			_hp;
		int			_ep;
		int			_ad;

	public:
					ClapTrap( void );
					ClapTrap( std::string name );
					ClapTrap( ClapTrap const& src );
					~ClapTrap( void );

		ClapTrap&	operator=( ClapTrap const& rhs );

		void		attack( std::string const& target );
		void		takeDamage( unsigned int amount );
		void		beRepaired( unsigned int amount );

};