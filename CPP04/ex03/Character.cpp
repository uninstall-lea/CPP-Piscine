#include "Character.hpp"
#include "ICharacter.hpp"

ICharacter::~ICharacter( void ) {

}

/* -------------------------------------------------------------------------- */
/*                          Constructor / Destructor                          */
/* -------------------------------------------------------------------------- */

Character::Character( void ) : _name("noName") {

	_items[0] = NULL;
	_items[1] = NULL;
	_items[2] = NULL;
	_items[3] = NULL;
}

Character::Character( std::string name ) : _name(name) {

	_items[0] = NULL;
	_items[1] = NULL;
	_items[2] = NULL;
	_items[3] = NULL;
}

Character::Character( Character const& src ) {

	*this = src;
}

Character& Character::operator=( Character const& rhs ) {

	*this = Character();
	_name = rhs._name;

	for (int i = 0; i < 4; i++) {
		if (_items[i]) {
			delete _items[i];
			_items[i] = NULL;
		}
		if (rhs._items[i])
			_items[i] = rhs._items[i]->clone();
	}

	return (*this);

}
Character::~Character( void ) {

	for (int i = 0; i < 4; i++)
		delete _items[i];
}

/* -------------------------------------------------------------------------- */
/*                                  Functions                                 */
/* -------------------------------------------------------------------------- */

std::string const& Character::getName( void ) const {

	return (_name);
}

void Character::equip(AMateria* m) {

	for (int i = 0; i < 4; i++)
		if (!_items[i]) {
			_items[i] = m;
			break;
		}
}

void Character::unequip(int idx) {

	_items[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {

	_items[idx]->use(target);
}