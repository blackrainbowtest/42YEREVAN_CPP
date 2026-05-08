/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:05:33 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/08 20:05:34 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = value << this->_bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << this->_bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &src)
		this->_value = src.getRawBits();
	return (*this);
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