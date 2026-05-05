/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 16:14:52 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/05 21:23:06 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>
#include <iostream>

class Fixed
{
	int		_value;
	static const int		_bits;
	public:
	Fixed();
	Fixed(const Fixed& copy);
	~Fixed();
	
	Fixed&	operator=(const Fixed& src);

	int		getRawBits(void)const;
	void	setRawBits(int const raw);
};
#endif // FIXED_HPP
