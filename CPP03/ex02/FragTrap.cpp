#include "FragTrap.hpp"

/* -------------------------------------------------------------------------- */
/*                          Constructor & Destructor                          */
/* -------------------------------------------------------------------------- */

FragTrap::FragTrap( void ) : ClapTrap() {

	_hp = 100;
	_ep = 100;
	_ad = 30;
	std::cout << "FragTrap: " << _name << " Default constructor called" << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name) {

	_hp = 100;
	_ep = 100;
	_ad = 30;
	std::cout << "FragTrap: " << _name << " Constructor called" << std::endl;
}

FragTrap::FragTrap( FragTrap const& src ) : ClapTrap(src) {

	std::cout	<< "FragTrap: " << _name << " Copy constructor called" << std::endl;
}

FragTrap::~FragTrap( void ) {

	std::cout	<< "FragTrap: " << _name << " Destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                            Assignation Operator                            */
/* -------------------------------------------------------------------------- */

FragTrap&	FragTrap::operator=( FragTrap const& rhs ) {

	_name = rhs._name;
	_hp = rhs._hp;
	_ep = rhs._ep;
	_ad = rhs._ad;

	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                                  Functions                                 */
/* -------------------------------------------------------------------------- */

// void	FragTrap::attack( const std::string& target ) {

// 	if (_hp && _ep)
// 	{
// 		std::cout	<< "FragTrap: " << _name << " attacks " << target
// 					<< ", causing " << _ad << " points of damage !" << std::endl;
// 		_ep--;
// 	}
// 	else
// 		std::cout	<< "FragTrap: " << _name
// 					<< " is either ko or low energy" << std::endl;
// }

void	FragTrap::highFivesGuys( void ) {

	std::cout	<< "FragTrap: " << _name << " wants a high fives !" << std::endl;
}