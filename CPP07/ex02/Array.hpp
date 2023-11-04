#pragma once

#include <string>
#include <iostream>

template<typename T>
class	Array {

	private:
		T*					_tab;
		unsigned int		_size;

	public:
							Array( void );
							Array( unsigned int n);
							Array( Array const& src );
							~Array( void );

/* -------------------------------------------------------------------------- */

							Array& operator=( Array const& rhs );
							T& operator[]( unsigned int idx );

/* -------------------------------------------------------------------------- */

		unsigned int const&	size( void ) const;

/* -------------------------------------------------------------------------- */

	class	IndexOutOfBounds : public std::exception {
		public:
			virtual const char* what() throw() {
				return ("Index is out of bounds");
			}
	};

};

