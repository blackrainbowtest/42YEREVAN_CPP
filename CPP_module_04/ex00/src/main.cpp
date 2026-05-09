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
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define BLACK "\033[30m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN "\033[46m"
#define RESET "\033[0m"

static void	printDivider(void)
{
	std::cout << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << std::endl;
}

static void	printSection(const std::string& title)
{
	printDivider();
	std::cout << "\033[34m" << title << "\033[0m" << std::endl;
	std::cout << std::endl;
}

int	main(void)
{
	printSection("Animal");
	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	const Animal	*meta = new Animal();
	std::cout << std::endl;
	std::cout << "\033[34mTesting\033[0m" << std::endl;

	std::cout << "Animal _type: " << meta->getType() << std::endl;
	meta->makeSound();
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	delete meta;
	std::cout << std::endl;

	printSection("Cat via Animal pointer");
	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	const Animal	*catto = new Cat();
	std::cout << std::endl;

	std::cout << "\033[34mTesting\033[0m" << std::endl;
	std::cout << "Cat _type: " << catto->getType() << std::endl;
	catto->makeSound();
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	delete catto;
	std::cout << std::endl;

	printSection("Dog via Animal pointer");
	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	const Animal	*doggo = new Dog();
	std::cout << std::endl;
	std::cout << "\033[34mTesting\033[0m" << std::endl;
	std::cout << "Dog _type: " << doggo->getType() <<std::endl;
	doggo->makeSound();
	std::cout << std::endl;
	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	delete doggo;
	std::cout << std::endl;

	printSection("WrongAnimal");
	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	const WrongAnimal	*wrong_meta = new WrongAnimal();
	std::cout << std::endl;

	std::cout << "\033[34mTesting\033[0m" << std::endl;
	std::cout << "Animal _type: " << wrong_meta->getType() << std::endl;
	wrong_meta->makeSound();
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	delete wrong_meta;
	std::cout << std::endl;

	printSection("WrongCat via WrongAnimal pointer");
	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	const WrongAnimal	*wrong_catto = new WrongCat();
	std::cout << std::endl;

	std::cout << "\033[34mTesting\033[0m" << std::endl;
	std::cout << "WrongCat _type: " << wrong_catto->getType() <<std::endl;
	wrong_catto->makeSound();
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	delete wrong_catto;
	std::cout << std::endl;

	printSection("WrongCat direct pointer");
	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	const WrongCat	*wrong_catta = new WrongCat();
	std::cout << std::endl;

	std::cout << "\033[34mTesting\033[0m" << std::endl;
	std::cout << "WrongCat _type: " << wrong_catta->getType() <<std::endl;
	wrong_catta->makeSound();
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	delete wrong_catta;
	std::cout << std::endl;
	
	return (EXIT_SUCCESS);
}
