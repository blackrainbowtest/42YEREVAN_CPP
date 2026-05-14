/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:54:04 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/14 18:28:44 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>

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
	printSection("POLYMORPHISM TEST");
	{
		const Animal*	meta[10];

		std::cout << CYAN << "Constructing animals..." << RESET << std::endl;
		for (int i = 0; i < 10; i++)
		{
			if (i % 2 == 0)
				meta[i] = new Dog();
			else
				meta[i] = new Cat();
		}

		std::cout << std::endl;
		std::cout << CYAN << "Testing sounds..." << RESET << std::endl;
		for (int i = 0; i < 10; i++)
		{
			std::cout << "Type: " << meta[i]->getType() << std::endl;
			meta[i]->makeSound();
		}

		std::cout << std::endl;
		std::cout << MAGENTA << "Deleting animals..." << RESET << std::endl;
		for (int i = 0; i < 10; i++)
			delete meta[i];
	}

	printSection("COPY CONSTRUCTOR DEEP COPY TEST");
	{
		Dog	original;

		original.setIdea(0, "I want meat");
		original.setIdea(1, "I want to sleep");
		original.setIdea(2, "I want to bark");

		Dog	copy(original);

		original.setIdea(0, "I changed my mind");

		std::cout << CYAN << "ORIGINAL:" << RESET << std::endl;
		original.getIdeas();

		std::cout << std::endl;
		std::cout << CYAN << "COPY:" << RESET << std::endl;
		copy.getIdeas();
	}

	printSection("ASSIGNMENT OPERATOR DEEP COPY TEST");
	{
		Cat	a;
		Cat	b;

		a.setIdea(0, "Sleep");
		a.setIdea(1, "Hunt mice");

		b = a;

		a.setIdea(0, "Different idea");

		std::cout << CYAN << "A:" << RESET << std::endl;
		a.getIdeas();

		std::cout << std::endl;
		std::cout << CYAN << "B:" << RESET << std::endl;
		b.getIdeas();
	}

	printSection("SURVIVAL AFTER ORIGINAL DESTRUCTION TEST");
	{
		Dog*	original = new Dog();

		original->setIdea(0, "Protect the house");
		original->setIdea(1, "Eat food");

		Dog*	copy = new Dog(*original);

		delete original;

		std::cout << CYAN
			<< "COPY AFTER ORIGINAL DELETION:"
			<< RESET << std::endl;
		copy->getIdeas();

		delete copy;
	}

	printSection("OUT OF RANGE TEST");
	{
		Dog	test;

		test.setIdea(101, "This should fail");
		test.setIdea(999, "This should also fail");
	}
	
		return (EXIT_SUCCESS);
}
