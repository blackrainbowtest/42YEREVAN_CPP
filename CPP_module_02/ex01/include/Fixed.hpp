/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 16:14:52 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/05 21:33:16 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>

class Fixed
{
	int		_value;
	static const int		_bits;
	public:
	Fixed();
	Fixed(const Fixed& copy);
	Fixed(const int value);
	Fixed(const float value);
	~Fixed();
	
	Fixed&	operator=(const Fixed& src);

	int		getRawBits(void)const;
	void	setRawBits(int const raw);

	float	toFloat(void) const;
	int		toInt(void) const;
};
std::ostream& operator<<(std::ostream& os, const Fixed& src);

#endif // FIXED_HPP
