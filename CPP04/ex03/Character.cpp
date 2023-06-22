#include "Character.hpp"

/* -------------------------------------------------------------------------- */
/*                          Constructor / Destructor                          */
/* -------------------------------------------------------------------------- */

Character::Character( void ) : _name("noName") {

}

Character::Character( std::string name ) : _name(name) {

}

Character::Character( Character const& src ) {

	*this = src; //Assignation operator is define and do a deep copy
}

Character& Character::operator=( Character const& rhs ) {

	*this = Character();
	_name = rhs._name;
	for (int i = 0; i < 4; i++)
		_items[i] = rhs._items[i];

	return (*this);

}
Character::~Character( void ) {

	delete[] _items;
}

/* -------------------------------------------------------------------------- */
/*                                  Functions                                 */
/* -------------------------------------------------------------------------- */

std::string const& Character::getName( void ) const {

	return (_name);
}

void Character::equip(AMateria* m) {

	for (int i = 0; i < 4; i++)
		if (_items[i])
			_items[i] = m;
}

void Character::unequip(int idx) {

}

void Character::use(int idx, ICharacter& target) {

	_items[idx]->use(target);
}