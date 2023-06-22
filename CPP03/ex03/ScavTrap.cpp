#include "ScavTrap.hpp"

/* -------------------------------------------------------------------------- */
/*                          Constructor & Destructor                          */
/* -------------------------------------------------------------------------- */

ScavTrap::ScavTrap( void ) : ClapTrap() {

	_hp = 100;
	_ep = 50;
	_ad = 20;
	std::cout << "ScavTrap: " << _name << " Default constructor called" << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name) {

	_hp = 100;
	_ep = 50;
	_ad = 20;
	std::cout << "ScavTrap: " << _name << " Constructor called" << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const& src ) : ClapTrap(src) {

	std::cout	<< "ScavTrap: " << _name << " Copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap( void ) {

	std::cout	<< "ScavTrap: " << _name << " Destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                            Assignation Operator                            */
/* -------------------------------------------------------------------------- */

ScavTrap&	ScavTrap::operator=( ScavTrap const& rhs ) {

	_name = rhs._name;
	_hp = rhs._hp;
	_ep = rhs._ep;
	_ad = rhs._ad;

	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                                  Functions                                 */
/* -------------------------------------------------------------------------- */

void	ScavTrap::attack( const std::string& target ) {

	if (_hp && _ep)
	{
		std::cout	<< "ScavTrap: " << _name << " attacks " << target
					<< ", causing " << _ad << " points of damage !" << std::endl;
		_ep--;
	}
	else
		std::cout	<< "ScavTrap: " << _name
					<< " is either ko or low energy" << std::endl;
}

void	ScavTrap::guardGate( void ) {

	std::cout	<< "ScavTrap: " << _name << " has entered Gate Keeper mode" << std::endl;
}