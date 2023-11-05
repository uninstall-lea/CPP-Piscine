#pragma once

#include "Array.hpp"

template<typename T>
Array<T>::Array( void ) : _tab(new T[0]), _size(0) {

}

template<typename T>
Array<T>::Array( unsigned int n ) : _tab(new T[n]), _size(n) {

}

template<typename T>
Array<T>::Array( Array const& src )
	: _tab(new T[src.size()]) ,_size(src.size()) {

	for (unsigned idx = 0; idx < size(); idx++)
		_tab[idx] = src._tab[idx];
}

template<typename T>
Array<T>::~Array( void ) {

	delete[] _tab;
}

/* -------------------------------------------------------------------------- */

template<typename T>
Array<T>&	Array<T>::operator=( Array const& rhs ) {

	delete[] _tab;

	_tab = new T[rhs.size()];
	_size = rhs.size();

	for (unsigned idx = 0; idx < size(); idx++)
		_tab[idx] = rhs._tab[idx];

	return (*this);
}

template<typename T>
T&	Array<T>::operator[]( unsigned int idx ) {

	if (idx >= size())
		throw IndexOutOfBounds();
	else
		return (_tab[idx]);
}

/* -------------------------------------------------------------------------- */

template<typename T>
unsigned int const&	Array<T>::size( void ) const {

	return (_size);
}
