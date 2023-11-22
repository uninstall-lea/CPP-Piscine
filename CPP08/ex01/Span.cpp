#include "Span.hpp"
#include <cstdlib>

Span::Span( void ) : _size(0) {

}

Span::Span( unsigned int const N ): _size(N) {

}

Span::Span( Span const& src ) : _size(src._size) {

	_vec.clear();
	_vec.insert(_vec.begin(), src._vec.begin(), src._vec.end());
}

Span::~Span( void ) {

}

Span&	Span::operator=( Span const& rhs ) {

	_vec.clear();
	_vec.insert(_vec.begin(), rhs._vec.begin(), rhs._vec.end());
	_size = rhs._size;
	return (*this);
}

/*----------------------------------------------------------------------------*/

void	Span::addNumber( int n ) {

	if (_vec.size() == _size)
		throw std::length_error("Span is full");
	else
		_vec.push_back(n);
}

void	Span::addNumber( std::vector<int>::iterator first, std::vector<int>::iterator last ) {

	for (;first != last; first++) {
		if (_vec.size() == _size)
			throw std::length_error("Span is full");
		addNumber(*first);
	}
}

int		Span::shortestSpan( void ) {

	if (_size < 2)
		throw std::logic_error("Not enough elements in Span");

	std::vector <int> copy = _vec;
	std::sort(copy.begin(), copy.end());
	int minSpan = copy[1] - copy[0];

	 for (unsigned int i = 1; i < copy.size() - 1; ++i) {
        int span = copy[i+1] - copy[i];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int		Span::longestSpan( void ) {

	if (_size < 2)
		throw std::logic_error("Not enough elements in Span");

	std::vector <int> copy = _vec;

	std::sort(copy.begin(), copy.end());
	return (copy.back() - copy.front());
}