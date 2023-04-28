#include "HumanA.hpp"

/* -------------------------------------------------------------------------- */
/*                                 Const/Destr                                */
/* -------------------------------------------------------------------------- */

HumanA::HumanA( std::string name, Weapon const & weapon ) : _name(name), _weapon(weapon) {

}

HumanA::~HumanA ( void ) {

}

/* -------------------------------------------------------------------------- */
/*                               Member Function                              */
/* -------------------------------------------------------------------------- */


void	HumanA::attack(void) {

	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}