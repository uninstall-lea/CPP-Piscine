#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

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
		void				addNumber( std::vector<int>::iterator first, std::vector<int>::iterator last, int n );
		int					shortestSpan( void );
		int					longestSpan( void );

/* -------------------------------------------------------------------------- */

		class	MaxElementsReached : public std::exception {
			public :
				virtual const char* what() const throw() {
					return ("Maximum elements reached for this array");
				}
		};

		class	NotEnoughElemToCompute : public std::exception {
			public :
				virtual const char* what() const throw() {
					return ("Not enough elements in the array to compute shortestSpan or longestSpan");
				}
		};

};

