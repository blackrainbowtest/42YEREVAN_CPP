/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:07:17 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/08 20:21:25 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
	// Constructor
		WrongCat();
		WrongCat(const WrongCat& copy);
	// Destructor
		~WrongCat();
	// Overloaded operator
		WrongCat &operator=(const WrongCat& src);
	// methods
		void	makesound(void)const;
};

#endif // !WRONG_CAT_HPP