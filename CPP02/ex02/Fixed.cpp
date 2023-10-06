#include "Fixed.hpp"

const int	Fixed::_bits = 8;

/* -------------------------------------------------------------------------- */
/*                                 Const/Destr                                */
/* -------------------------------------------------------------------------- */

Fixed::Fixed( void ) : _value(0) {

	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const& src ) {

	// std::cout << "Copy constructor called" << std::endl;

	*this = src;
}

Fixed::Fixed( const int& value ) {

	// std::cout << "Int constructor called" << std::endl;

	this->_value = value << _bits;
}

Fixed::Fixed ( const float& value ) {

	// std::cout << "Float constructor called" << std::endl;

	this->_value = roundf(value * (1 << _bits));
}

Fixed::~Fixed( void ) {

	// std::cout << "Destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                                  Operator                                  */
/* -------------------------------------------------------------------------- */
/* --------------------------------- Member --------------------------------- */

Fixed&	Fixed::operator=( Fixed const& rhs ) {

	// std::cout << "Copy assignment operator called" << std::endl;

	this->_value = rhs.getRawBits();

	return (*this);
}

// Operator comparison ---------------------------------------------------------
bool	Fixed::operator>( Fixed const& rhs ) {

	return (_value > rhs._value ? true : false);
}

bool	Fixed::operator<( Fixed const& rhs ) {

	return (_value < rhs._value ? true : false);
}

bool	Fixed::operator>=( Fixed const& rhs ) {

	return (_value >= rhs._value ? true : false);
}

bool	Fixed::operator<=( Fixed const& rhs ) {

	return (_value <= rhs._value ? true : false);
}

bool	Fixed::operator==( Fixed const& rhs ) {

	return (_value == rhs._value ? true : false);
}

bool	Fixed::operator!=( Fixed const& rhs ) {

	return (_value != rhs._value ? true : false);
}

// Operator arithmetic ---------------------------------------------------------
Fixed	Fixed::operator+( Fixed const& rhs ) {

	return Fixed(_value + rhs._value);
}

Fixed	Fixed::operator-( Fixed const& rhs ) {

	return Fixed(_value - rhs._value);
}

Fixed	Fixed::operator*( Fixed const& rhs ) {

	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/( Fixed const& rhs ) {

	return Fixed(this->toFloat() / rhs.toFloat());
}

// Operator ++i/--i ------------------------------------------------------------
Fixed	Fixed::operator++( void ) {

	++_value;
	return (*this);
}

Fixed	Fixed::operator--( void ) {

	--_value;
	return (*this);
}

// Operator i++/i++ ------------------------------------------------------------
Fixed	Fixed::operator++( int ) {

	Fixed tmp(*this);
	_value++;
	return (tmp);
}

Fixed	Fixed::operator--( int ) {

	Fixed tmp(*this);
	_value--;
	return (tmp);
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

Fixed		&Fixed::min( Fixed& lhs, Fixed& rhs) {

	return (lhs._value < rhs._value ? lhs : rhs);
}

Fixed		&Fixed::max( Fixed& lhs, Fixed& rhs) {

	return (lhs._value > rhs._value ? lhs : rhs);
}

const Fixed	&Fixed::min( Fixed const& lhs, Fixed const& rhs) {

	return (lhs._value < rhs._value ? lhs : rhs);
}

const Fixed	&Fixed::max( Fixed const& lhs, Fixed const& rhs) {

	return (lhs._value > rhs._value ? lhs : rhs);
}
