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
		
		/* Operator assignation */
		Fixed&	operator=( Fixed const& rhs );

		/* Operator comparison */
		bool	operator>( Fixed const& rhs );
		bool	operator<( Fixed const& rhs );
		bool	operator>=( Fixed const& rhs );
		bool	operator<=( Fixed const& rhs );
		bool	operator==( Fixed const& rhs );
		bool	operator!=( Fixed const& rhs );

		/* Operator arithmetic */
		Fixed	operator+( Fixed const& rhs );
		Fixed	operator-( Fixed const& rhs );
		Fixed	operator*( Fixed const& rhs );
		Fixed	operator/( Fixed const& rhs );

		/* Operator ++i/--i */
		Fixed	operator++( void );
		Fixed	operator--( void );

		/* Operator i++/i-- */
		Fixed	operator++( int );
		Fixed	operator--( int );

		/* Functions */
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		int		toInt( void ) const;
		float	toFloat( void ) const;

		static Fixed		&min( Fixed& lhs, Fixed& rhs);
		static Fixed		&max( Fixed& lhs, Fixed& rhs);
		static const Fixed	&min( Fixed const& lhs, Fixed const& rhs);
		static const Fixed	&max( Fixed const& lhs, Fixed const& rhs);

};

std::ostream& operator<<( std::ostream& o, Fixed const& rhs);
