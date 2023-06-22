#pragma once

#include <iostream>
#include <cmath>

class	Fixed {

	private:
		int					_value;
		static const int	_bits;

	public:
				Fixed( void );
				Fixed( Fixed const& src );
				Fixed( const int& value );
				Fixed ( const float& value );
				~Fixed( void );
		
		Fixed&	operator=( Fixed const& rhs );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		int		toInt( void ) const;
		float	toFloat( void ) const;

};

std::ostream& operator<<( std::ostream& o, Fixed const& rhs);
