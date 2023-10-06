#include "ClapTrap.hpp"

int	main ( void ) {

	ClapTrap	badGuy("Bowser");
	ClapTrap	niceGuy("Mario");
	ClapTrap	toad("Toad");

	std::cout << std::endl;

	badGuy.attack("Mario");
	niceGuy.takeDamage(5);
	niceGuy.beRepaired(5);

	std::cout << std::endl;

	badGuy.attack("Toad");
	toad.takeDamage(100);
	toad.beRepaired(1);

	std::cout << std::endl;

	return (0);
}