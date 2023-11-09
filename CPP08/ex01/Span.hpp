#pragma once

#include <string>
#include <iostream>
#include <vector>

class	Span {

	private:
		std::vector<int>	_vec;
		unsigned int		_size;

	public:
							Span( void );
							Span( unsigned int const N );
							Span( Span const& src );
							~Span( void );

							Span& operator=( Span const& rhs );

		void				addNumber( int n );
		int					shortestSpan( void );
		int					longestSpan( void );

};

#include "Span.hpp"

Span::Span( void ) : _size(0) {}

Span::Span( unsigned int const N ): _size(N) {}

Span::Span( Span const& src ) {

	_vec.clear();
	_vec.insert(src._vec.begin(), src._size);
	_size = src._size;
}

Span::~Span( void ) {}

Span&	Span::operator=( Span const& rhs ) {

	_vec.clear();
	_vec.insert(rhs._vec.begin(), rhs._size);
	_size = rhs._size;
	return (*this);
}

/*----------------------------------------------------------------------------*/

void	Span::addNumber( int n ) {

		std::iterarator it = _vec.begin();	
}
int		shortestSpan( void );
int		longestSpan( void );