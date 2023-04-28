#include "Zombie.hpp"

int	main( void ) {

	Zombie 	jim("jim");
	Zombie* bob = newZombie("bob");

	jim.announce();
	bob->announce();
	randomChump("ben");

	delete bob;
	return (0);
}