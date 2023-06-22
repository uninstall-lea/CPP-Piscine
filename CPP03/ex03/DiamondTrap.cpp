#include "DiamondTrap.hpp"

/* -------------------------------------------------------------------------- */
/*                          Constructor & Destructor                          */
/* -------------------------------------------------------------------------- */

DiamondTrap::DiamondTrap( void ) : 
	ClapTrap(), ScavTrap(), FragTrap() {

	_name = "noName";
	_hp = FragTrap::_hp;
	_ep = ScavTrap::_ep;
	_ad = FragTrap::_ad;
	std::cout << "DiamondTrap: " << _name << " Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) :
	ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap() {

	_name = name;
	_hp = FragTrap::_hp;
	_ep = ScavTrap::_ep;
	_ad = FragTrap::_ad;
	std::cout << "DiamondTrap: " << _name << " Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap const& src ) :
	ClapTrap(src), ScavTrap(src), FragTrap(src) {

	std::cout	<< "DiamondTrap: " << _name << " Copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap( void ) {

	std::cout	<< "DiamondTrap: " << _name << " Destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                            Assignation Operator                            */
/* -------------------------------------------------------------------------- */

DiamondTrap&	DiamondTrap::operator=( DiamondTrap const& rhs ) {

	_name = rhs._name;
	_hp = rhs._hp;
	_ep = rhs._ep;
	_ad = rhs._ad;

	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                                  Functions                                 */
/* -------------------------------------------------------------------------- */

void	DiamondTrap::attack( const std::string& target ) {

	ScavTrap::attack(target);
}

void 	DiamondTrap::whoAmI( void ) {

	std::cout	<< "DiamondTrap: my child name is: " << _name << std::endl;
	std::cout	<< "DiamondTrap: my parent name is: " << ClapTrap::_name << std::endl;
}