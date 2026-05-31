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
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "color_palletre.hpp"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

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
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	printSection("GRADE TOO HIGH ON CONSTRUCTION");

	try
	{
		Bureaucrat boss("Boss", 0);
		std::cout << boss << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	printSection("GRADE TOO LOW ON CONSTRUCTION");

	try
	{
		Bureaucrat intern("Intern", 151);
		std::cout << intern << std::endl;
	}
	catch (std::exception &e)
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
	catch (std::exception &e)
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
	catch (std::exception &e)
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
	catch (std::exception &e)
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
	catch (std::exception &e)
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
	catch (std::exception &e)
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
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	printSection("VALID FORM");

	try
	{
		Form permit("Permit", 50, 20);

		std::cout << permit << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	printSection("INVALID SIGN GRADE");

	try
	{
		Form bad("Bad", 0, 20);

		std::cout << bad << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	printSection("INVALID EXEC GRADE");

	try
	{
		Form bad("Bad", 20, 151);

		std::cout << bad << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	printSection("FORM SIGN SUCCESS");

	try
	{
		Bureaucrat boss("Boss", 10);
		Form permit("Permit", 50, 20);

		std::cout << permit << std::endl;

		permit.beSigned(boss);

		std::cout << permit << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	printSection("FORM SIGN FAILURE");

	try
	{
		Bureaucrat intern("Intern", 120);
		Form permit("Permit", 50, 20);

		intern.signForm(permit);

		std::cout << permit << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	printSection("FORM COPY CONSTRUCTOR");

	try
	{
		Form original("Original", 50, 20);
		Form copy(original);

		std::cout << original << std::endl;
		std::cout << copy << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	printSection("FORM ASSIGNMENT");

	try
	{
		Form a("A", 50, 20);
		Form b("B", 100, 80);

		std::cout << a << std::endl;
		std::cout << b << std::endl;

		b = a;

		std::cout << a << std::endl;
		std::cout << b << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	
	return (EXIT_SUCCESS);
}
