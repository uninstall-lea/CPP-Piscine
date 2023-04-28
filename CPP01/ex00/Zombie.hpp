#pragma once

# include <string>

/* ------------------------------ class Zombie ------------------------------ */

class Zombie {

	private:
		std::string _name;

	public:
		Zombie( std::string name);
		~Zombie( void );

		void	announce( void );
};

/* --------------------------- Not member function -------------------------- */

void	randomChump( std::string name );
Zombie*	newZombie( std::string name );