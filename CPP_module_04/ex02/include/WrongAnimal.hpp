/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:07:14 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/08 20:24:09 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
	protected:
		std::string _type;
	public:
	// Constructor
		WrongAnimal();
		WrongAnimal(const WrongAnimal& copy);
	// Destructor
		~WrongAnimal();
	// Overloaded operator
		WrongAnimal &operator=(const WrongAnimal& src);
	// methods
		void	makeSound(void)const;
	// get
		std::string getType(void)const;
};

#endif // !WRONG_ANIMAL_HPP