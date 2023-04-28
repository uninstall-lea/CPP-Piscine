#include "Zombie.hpp"
#include <iostream>

/* -------------------------------------------------------------------------- */
/*                           Constructor/Destructor                           */
/* -------------------------------------------------------------------------- */

Zombie::Zombie(void) {

}

Zombie::Zombie( std::string name ) : _name(name) {

	std::cout << name << " rises from the dead" << std::endl;
}

Zombie::~Zombie( void ) {

	std::cout << this->_name << " is now dead-dead" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                               Member function                              */
/* -------------------------------------------------------------------------- */

void	Zombie::announce( void ) { 

	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName( std::string name ) {

	this->_name = name;
}