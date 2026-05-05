/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 16:14:52 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/05 22:18:02 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>

class Fixed
{
	int						_value;
	static const int		_bits;
	
	public:
	Fixed();
	Fixed(const Fixed& copy);
	Fixed(const int value);
	Fixed(const float value);
	
	~Fixed();
	
	// operators
	Fixed&	operator=(const Fixed& src);
	Fixed	operator+(const Fixed& src) const;
	Fixed	operator-(const Fixed& src) const;
	Fixed	operator*(const Fixed& src) const;
	Fixed	operator/(const Fixed& src) const;
	
	// comparison operators
	bool	operator>(const Fixed& src) const;
	bool	operator<(const Fixed& src) const;
	bool	operator>=(const Fixed& src) const;
	bool	operator<=(const Fixed& src) const;
	bool	operator==(const Fixed& src) const;
	bool	operator!=(const Fixed& src) const;
	
	// increment/decrement operators
	Fixed&	operator++(); // prefix increment
	Fixed	operator++(int); // postfix increment
	Fixed&	operator--(); // prefix decrement
	Fixed	operator--(int); // postfix decrement
	
	// static member functions
	static Fixed&	min(Fixed& a, Fixed& b);
	static const Fixed&	min(const Fixed& a, const Fixed& b);
	static Fixed&	max(Fixed& a, Fixed& b);
	static const Fixed&	max(const Fixed& a, const Fixed& b);
	
	// member functions
	int		getRawBits(void)const;
	void	setRawBits(int const raw);
	// conversion functions
	float	toFloat(void) const;
	int		toInt(void) const;
};
// non-member function
std::ostream& operator<<(std::ostream& os, const Fixed& src);

#endif // FIXED_HPP
