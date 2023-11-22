#include "Span.hpp"
#include <cstdlib>

Span::Span( void ) : _size(0) {

}

Span::Span( unsigned int const N ): _size(N) {

}

Span::Span( Span const& src ) {

	_vec.clear();
	_vec.insert(src._vec.begin(), src._size);
	_size = src._size;
}

Span::~Span( void ) {

}

Span&	Span::operator=( Span const& rhs ) {

	_vec.clear();
	_vec.insert(rhs._vec.begin(), rhs._size);
	_size = rhs._size;
	return (*this);
}

/*----------------------------------------------------------------------------*/

void	Span::addNumber( int n ) {

	if (_size > _vec.size())
		throw MaxElementsReached();
	else
		_vec.push_back(n);
}

void	Span::addNumber( std::vector<int>::iterator first, std::vector<int>::iterator last) {

	if (_size > _vec.size())
		throw MaxElementsReached();

	while (first < last)
		*first = rand(), first++;
}

int		Span::shortestSpan( void ) {

	int	value = *_vec.begin();

	if (_vec.size() <= 1)
		throw NotEnoughElemToCompute();

	for (std::vector<int>::iterator it = _vec.begin(); it < _vec.end(); it++)
		if (value < *it)
			value = *it;

	return (value);
}

int		Span::longestSpan( void ) {

	int	value = *_vec.begin();

	if (_vec.size() <= 1)
		throw NotEnoughElemToCompute();

	for (std::vector<int>::iterator it = _vec.begin(); it < _vec.end(); it++)
		if (value > *it)
			value = *it;

	return (value);
}