#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	bowser("Bowser");
	ClapTrap	mario("Mario");
	ClapTrap	luigi("Luigi");

	bowser.attack("Luigi");
	luigi.takeDamage(20);
	luigi.attack("Bowser");
	for(int i = 0; i < 11; i++)
		mario.beRepaired(1);
	bowser.guardGate();

	return (0);
}