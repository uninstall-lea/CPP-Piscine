#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) : _idx(0) {

	for(int i = 0; i < 4; i++)
		_stock[i] = NULL;
}

MateriaSource::MateriaSource( MateriaSource const& src ) {

	*this = src;
}

MateriaSource::~MateriaSource( void ) {

	for (int i(0); i < 4; i++)
		delete	_stock[i];
}

MateriaSource&	MateriaSource::operator=( MateriaSource const& rhs ) {

	_idx = rhs._idx;
	
	for (int i = 0; i < rhs._idx; i++) {
		if (_stock[i])
			delete _stock[i];
		_stock[i] = rhs._stock[i];
	}

	return (*this);
}

/* -------------------------------------------------------------------------- */

void		MateriaSource::learnMateria( AMateria* src ) {

	for (int i = 0; i < 4; i++)
		if (!_stock[i]) {
			_stock[i] = src;
			_idx = i;
			break;
		}
}

AMateria*	MateriaSource::createMateria( std::string const& type ) {

	if (type != "ice" || type != "cure")
		return (0);
	
	AMateria* newMateria = _stock[_idx]->clone();

	return (newMateria);
}