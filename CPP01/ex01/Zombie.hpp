#pragma once

# include <string>

/* ------------------------------ class Zombie ------------------------------ */

class Zombie {

	private:
		std::string _name;


	public:
		Zombie( void );
		Zombie( std::string name );
		~Zombie( void );

		void	announce( void );
		void	setName( std::string name );

};

/* --------------------------- Not member function -------------------------- */

Zombie* zombieHorde( int N, std::string name );