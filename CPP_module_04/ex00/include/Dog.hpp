/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:07:12 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/08 20:21:16 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include <string>
# include "Animal.hpp"

class Dog: public Animal
{
	public:
	// Constructor
		Dog();
		Dog(const Dog& copy);
	// Destructor
		~Dog();
	// Overloaded operator
		Dog &operator=(const Dog& src);
	// methods
		void	makesound(void)const;
};

#endif // !DOG_HPP