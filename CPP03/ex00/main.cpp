#include "ClapTrap.hpp"

int	main ( void ) {

	ClapTrap	badGuy("Bowser");
	ClapTrap	niceGuy("Mario");

	badGuy.attack("Luigi");
	niceGuy.takeDamage(1);
	for (int i = 0; i < 11; i++)
		niceGuy.beRepaired(1);

	return (0);
}