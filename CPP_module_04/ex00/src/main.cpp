/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:54:04 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/09 00:05:04 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Animal.hpp"
#include "Cat.hpp"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define BLACK "\033[30m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN "\033[46m"
#define RESET "\033[0m"

int	main(void)
{
	// test default constructor
	std::cout << BG_MAGENTA << BLACK << "[test]"
		<< RESET << ": Testing default constructor"
		<< std::endl;
	Animal* animal = new Animal();
	Cat* cat = new Cat();
	
	// test makeSound
	std::cout << BG_MAGENTA << BLACK << "[test]"
		<< RESET << ": Testing makeSound() method"
		<< std::endl;
	animal->makeSound();
	cat->makeSound();
	
	// test copy constructor
	std::cout << BG_MAGENTA << BLACK << "[test]"
		<< RESET << ": Testing copy constructor"
		<< std::endl;
	Animal* animalCopy = new Animal(*animal);
	Cat* catCopy = new Cat(*cat);
	(void)animalCopy;
	(void)catCopy;
	
	// test assignation operator
	std::cout << BG_MAGENTA << BLACK << "[test]"
		<< RESET << ": Testing assignation operator"
		<< std::endl;
	Animal* animalAssign = new Animal();
	Cat* catAssign = new Cat();
	*animalAssign = *animal;
	*catAssign = *cat;
	
	return (EXIT_SUCCESS);
}
