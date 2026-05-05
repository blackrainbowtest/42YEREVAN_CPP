#include "Fixed.hpp"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define BLACK "\033[30m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN "\033[46m"
#define RESET "\033[0m"

const int Fixed::_bits = 8;

Fixed::Fixed(): _value(0)
{
}

Fixed::Fixed(const Fixed& copy)
{
	*this = copy;
}

Fixed::Fixed(const int value)
{
	this->_value = value << this->_bits;
}

Fixed::Fixed(const float value)
{
	this->_value = roundf(value * (1 << this->_bits));
}

Fixed::~Fixed()
{
}

float Fixed::toFloat(void) const
{
	return ((float)this->_value / (float)(1 << this->_bits));
}

int Fixed::toInt(void) const
{
	return (this->_value >> this->_bits);
}

// Overloaded operators
Fixed& Fixed::operator=(const Fixed& src)
{
	if(this != &src)
		this->_value = src.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed& src) const
{
	return (this->toFloat() > src.toFloat());
}

bool Fixed::operator<(const Fixed& src) const
{
	return (this->toFloat() < src.toFloat());
}

bool Fixed::operator>=(const Fixed& src) const
{
	return (this->toFloat() >= src.toFloat());
}

bool Fixed::operator<=(const Fixed& src) const
{
	return (this->toFloat() <= src.toFloat());
}

bool Fixed::operator==(const Fixed& src) const
{
	return (this->toFloat() == src.toFloat());
}

bool Fixed::operator!=(const Fixed& src) const
{
	return (this->toFloat() != src.toFloat());
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& src) const
{
	return (Fixed(this->toFloat() + src.toFloat()));
}

Fixed Fixed::operator-(const Fixed& src) const
{
	return (Fixed(this->toFloat() - src.toFloat()));
}

Fixed Fixed::operator*(const Fixed& src) const
{
	return (Fixed(this->toFloat() * src.toFloat()));
}

Fixed Fixed::operator/(const Fixed& src) const
{
	if (src.toFloat() == 0)
		throw std::runtime_error("Division by zero");
	return (Fixed(this->toFloat() / src.toFloat()));
}

// Increment/Decrement operators
Fixed& Fixed::operator++() // prefix increment
{
	this->_value += 1;
	return (*this);
}

Fixed Fixed::operator++(int) // postfix increment
{
	Fixed temp(*this);
	this->_value += 1;
	return (temp);
}

Fixed& Fixed::operator--() // prefix decrement
{
	this->_value -= 1;
	return (*this);
}

Fixed Fixed::operator--(int) // postfix decrement
{
	Fixed temp(*this);
	this->_value -= 1;
	return (temp);
}

// Static member functions
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b ? a : b);
}

// Getter
int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

// Setter
void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& src)
{
	os << src.toFloat();
	return (os);
}