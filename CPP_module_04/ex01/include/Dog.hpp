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
# include "Brain.hpp"

class Dog: public Animal
{
	Brain *_brain;
	public:
	// Constructor
		Dog();
		Dog(const Dog& copy);
	// Destructor
		~Dog();
	// Overloaded operator
		Dog &operator=(const Dog& src);
	// methods
		void	makeSound(void)const;
	// getter
		void getIdeas(void) const;
	// setter
		void setIdea(size_t index, const std::string& idea);
};

#endif // !DOG_HPP