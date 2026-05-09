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
	{
		printSection("Animal Creation and Polymorphism");

		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		const Animal *meta[10];
		for (int i = 0; i < 10; i++)
		{
			if (i % 2)
			{
				meta[i] = new Cat();
				if (meta[i] == NULL)
				{
					std::cerr << "Cat allocation failed" << std::endl;
					std::cerr << "Exiting process now" << std::endl;
					exit(1);
				}
			}
			else
			{
				meta[i] = new Dog();
				if (meta[i] == NULL)
				{
					std::cerr << "Dog allocation failed" << std::endl;
					std::cerr << "Exiting process now" << std::endl;
					exit(1);
				}
			}
		}
		std::cout << std::endl;

		std::cout << CYAN << "Testing" << RESET << std::endl;
		for (int i = 0; i < 10; i++)
		{
			std::cout << "Animal _type: " << meta[i]->getType() << std::endl;
			meta[i]->makeSound();
		}
		std::cout << std::endl;

		std::cout << MAGENTA << "Deconstructing" << RESET << std::endl;
		for (int i = 0; i < 10; i++)
			delete(meta[i]);




		// THIS PART IS FOR TESTING DEEP COPY ↓

		std::cout << std::endl << std::endl;
		std::cout << "#### showing that the copy constructor creates a deep copy ####" << std::endl;
		std::cout << std::endl;

		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Dog *a = new Dog();
		// Cat *a = new Cat();
		if (a == NULL)
		{
			std::cerr << "Allocation failed" << std::endl;
			std::cerr << "Exiting the process now." << std::endl;
			exit(1);
		}

		a->setIdea(0, "I have to eat");
		a->setIdea(1, "I have to sleep");
		a->setIdea(2, "I have to play");
		a->setIdea(3, "I have to bark");
		a->setIdea(4, "I have to wag my tail");
		a->setIdea(101, "some out of range idea"); // should trigger error message

		Dog *b = new Dog(*a);
		// Cat *b = new Cat(*a);
		if (b == NULL)
		{
			std::cerr << "Allocation failed" << std::endl;
			std::cerr << "Exiting the process now." << std::endl;
			exit(1);
		}
		std::cout << std::endl;

		std::cout << CYAN << "Testing a" << RESET << std::endl;
		std::cout << "The " << a->getType() << " a has the following ideas: " << std::endl;
		a->getIdeas();
		std::cout << std::endl;

		std::cout << CYAN << "Deconstructing a" << RESET << std::endl;
		delete(a);
		std::cout << std::endl;

		std::cout << CYAN << "Testing b" << RESET << std::endl;
		std::cout << "The " << b->getType() << " b has the following ideas: " << std::endl;
		b->getIdeas();
		std::cout << std::endl;

		std::cout << CYAN << "Deconstructing b" << RESET << std::endl;
		delete(b);

		return (EXIT_SUCCESS);
	}
}
