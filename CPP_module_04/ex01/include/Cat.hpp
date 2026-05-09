/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:07:09 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/08 20:07:09 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include <string>
# include "Animal.hpp"

class Cat: public Animal
{
	public:
	// Constructor
		Cat();
		Cat(const Cat &copy);
	// Destructor
		~Cat();
	// Operator Overloaded
		Cat &operator=(const Cat& src);
	// methods
		void	makeSound(void)const;
};

#endif // !CAT_HPP