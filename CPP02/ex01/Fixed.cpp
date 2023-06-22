#include "Fixed.hpp"

const int	Fixed::_bits = 8;

/* -------------------------------------------------------------------------- */
/*                                 Const/Destr                                */
/* -------------------------------------------------------------------------- */

Fixed::Fixed( void ) : _value(0) {

	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const& src ) {

	std::cout << "Copy constructor called" << std::endl;

	*this = src;
}

Fixed::Fixed( const int& value ) {

	std::cout << "Int constructor called" << std::endl;

	this->_value = value << _bits;
}

Fixed::Fixed ( const float& value ) {

	std::cout << "Float constructor called" << std::endl;

	this->_value = roundf(value * (1 << _bits));
}

Fixed::~Fixed( void ) {

	std::cout << "Destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                                  Operator                                  */
/* -------------------------------------------------------------------------- */
/* --------------------------------- Member --------------------------------- */

Fixed&	Fixed::operator=( Fixed const& rhs ) {

	std::cout << "Copy assignment operator called" << std::endl;

	this->_value = rhs.getRawBits();

	return (*this);
}

/* ------------------------------- Non Member ------------------------------- */

std::ostream&	operator<<( std::ostream& o, Fixed const& rhs) {

	o << rhs.toFloat();
	return (o);
}

/* -------------------------------------------------------------------------- */
/*                              Member Functions                              */
/* -------------------------------------------------------------------------- */

int		Fixed::getRawBits( void ) const {

	// std::cout << "getRawBits member function called" << std::endl;

	return (this->_value);
}

void	Fixed::setRawBits( int const raw ) {

	this->_value = raw;
}

int		Fixed::toInt( void ) const {

	return ((int)_value >> _bits);
}

float	Fixed::toFloat( void ) const {

	return ((float)_value / (1 << _bits));
}