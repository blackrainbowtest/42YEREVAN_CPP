/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 15:25:11 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/25 09:28:41 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "color_palletre.hpp"

#define EXIT_SUCCESS 0
// #define EXIT_FAILURE 1

static void	printDivider(void)
{
	std::cout << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << std::endl;
}

static void	printSection(const std::string& title)
{
	printDivider();
	std::cout << BLUE << title << RESET << std::endl;
	printDivider();
}

int	main(void)
{
	printSection("VALID CONSTRUCTION");

	try
	{
		Bureaucrat bob("Bob", 42);
		std::cout << GREEN << bob << RESET << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	printSection("GRADE TOO HIGH ON CONSTRUCTION");

	try
	{
		Bureaucrat boss("Boss", 0);
		std::cout << boss << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	printSection("GRADE TOO LOW ON CONSTRUCTION");

	try
	{
		Bureaucrat intern("Intern", 151);
		std::cout << intern << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	printSection("INCREMENT TEST");

	try
	{
		Bureaucrat chief("Chief", 2);

		std::cout << chief << std::endl;
		chief.incrementGrade();
		std::cout << chief << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	printSection("INCREMENT OVERFLOW");

	try
	{
		Bureaucrat king("King", 1);

		std::cout << king << std::endl;
		king.incrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	printSection("DECREMENT TEST");

	try
	{
		Bureaucrat worker("Worker", 149);

		std::cout << worker << std::endl;
		worker.decrementGrade();
		std::cout << worker << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	printSection("DECREMENT OVERFLOW");

	try
	{
		Bureaucrat noob("Noob", 150);

		std::cout << noob << std::endl;
		noob.decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	printSection("COPY CONSTRUCTOR");

	try
	{
		Bureaucrat original("Original", 10);
		Bureaucrat copy(original);

		std::cout << original << std::endl;
		std::cout << copy << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	printSection("ASSIGNMENT OPERATOR");

	try
	{
		Bureaucrat a("Alice", 50);
		Bureaucrat b("Bob", 120);

		std::cout << YELLOW << "Before assignment:" << RESET << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;

		b = a;

		std::cout << YELLOW << "After assignment:" << RESET << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	printSection("SELF ASSIGNMENT");

	try
	{
		Bureaucrat self("Self", 33);

		std::cout << self << std::endl;
		self = self;
		std::cout << self << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	printSection("DEFAULT CONSTRUCTOR");

	try
	{
		Bureaucrat def;
		std::cout << def << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	printSection("NAME ONLY CONSTRUCTOR");

	try
	{
		Bureaucrat named("OnlyName");
		std::cout << named << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	printSection("GRADE ONLY CONSTRUCTOR");

	try
	{
		Bureaucrat graded(77);
		std::cout << graded << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	return (EXIT_SUCCESS);
}
