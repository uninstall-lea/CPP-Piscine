#pragma once

#include <stack>
#include <algorithm>
#include <iostream>

template <typename T>
class	MutantStack : public std::stack<T> {

	public:

	//Methods for iterators
	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator	begin( void ) {
		return (this->c.begin());
	}
	iterator	end( void ) {
		return (this->c.end());
	}

/* -------------------------------------------------------------------------- */

	MutantStack( void ) {};
	MutantStack( MutantStack const& src ) : std::stack<T>(src) {};
	~MutantStack( void ) {};

	MutantStack& operator=( MutantStack const& rhs ) {
		this->c = rhs.c;
		return (*this);
	}

};
