#include "HumanB.hpp"

/* -------------------------------------------------------------------------- */
/*                                 Const/Destr                                */
/* -------------------------------------------------------------------------- */

HumanB::HumanB( std::string name ) : _name(name) {
	
	_weapon = NULL;
}

HumanB::~HumanB( void ) {

}

/* -------------------------------------------------------------------------- */
/*                               Member Function                              */
/* -------------------------------------------------------------------------- */

void	HumanB::setWeapon( Weapon & weapon) {

	_weapon = &weapon;
}

void	HumanB::attack(void) {

	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}