/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 16:14:52 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/05 18:55:19 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>
#include <iostream>

class Fixed
{
	int		_value;
	int		_bits;
	public:
	Fixed();
	Fixed(const Fixed& copy);
	~Fixed();
	
	Fixed& operator=(const Fixed& src);

	int	getRawBits(void)const;
	void	setRawBits(int const raw);
}
#endif // FIXED_HPP
