#include "ClapTrap.hpp"

/* -------------------------------------------------------------------------- */
/*                               Const/Destruct                               */
/* -------------------------------------------------------------------------- */

ClapTrap::ClapTrap(void) : 
	_name("noName"), _hp(10), _ep(10), _ad(0) {

	std::cout << "ClapTrap: " << _name << " Default constructor called" << std::endl;
}


ClapTrap::ClapTrap( std::string name ) :
	_hp(10), _ep(10), _ad(0) {

	_name = name;
	std::cout	<< "ClapTrap: " << _name << " Constructor called" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const& src ) :
	_name(src._name), _hp(src._hp), _ep(src._ep), _ad(src._ad) {

	std::cout	<< "ClapTrap: " << _name << " Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap( void ) {

	std::cout	<< "ClapTrap: " << _name << " Destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                            Assignation Operator                            */
/* -------------------------------------------------------------------------- */

ClapTrap&	ClapTrap::operator=( ClapTrap const& rhs ) {

	_name = rhs._name;
	_hp = rhs._hp;
	_ep = rhs._ep;
	_ad = rhs._ad;
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                                  Functions                                 */
/* -------------------------------------------------------------------------- */

void	ClapTrap::attack( const std::string& target ) {

	if (_hp > 0 && _ep > 0)
	{
		std::cout	<< "ClapTrap: " << _name << " attacks " << target
					<< ", causing " << _ad << " points of damage !" << std::endl;
		_ep--;
	}
	else
		std::cout	<< "ClapTrap: " << _name
					<< " is either ko or low energy" << std::endl;
}

void	ClapTrap::takeDamage( unsigned int amount ) {

	if (_hp > 0) {
	
		if (amount > (size_t) _hp)
			_hp = 0;
		else
			_hp -= amount;
		std::cout	<< "ClapTrap: " << _name << " take " << amount << " damage"
					<<" and has now " << _hp << " hp left !" << std::endl;
	}
	else
		std::cout	<< "ClapTrap: " << _name << "is already ko !" << std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount ) {

	if (_hp > 0 && _ep > 0)
	{
		_hp += amount;
		_ep--;
		std::cout	<< "ClapTrap: " << _name << " recover " << amount << " hp "
					<< "and has now " << _hp << " hp left !" << std::endl;
	}
	else
		std::cout	<< "ClapTrap: " << _name
					<< " is either ko or low energy" << std::endl;
}
