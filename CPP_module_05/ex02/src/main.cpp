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
#include <ctime>
#include <cstdlib>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
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

void testPresidentialSuccess()
{
	printTitle("PRESIDENTIAL PARDON SUCCESS");

	try
	{
		Bureaucrat president("President", 1);
		PresidentialPardonForm form("Arthur Dent");

		form.beSigned(president);
		form.execute(president);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void testUnsignedForm()
{
	printTitle("EXECUTE UNSIGNED FORM");

	try
	{
		Bureaucrat president("President", 1);
		PresidentialPardonForm form("Arthur Dent");

		form.execute(president);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void testGradeTooLowExecute()
{
	printTitle("GRADE TOO LOW TO EXECUTE");

	try
	{
		Bureaucrat intern("Intern", 150);
		PresidentialPardonForm form("Arthur Dent");

		Bureaucrat president("President", 1);
		form.beSigned(president);

		form.execute(intern);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void testGradeTooLowSign()
{
	printTitle("GRADE TOO LOW TO SIGN");

	try
	{
		Bureaucrat intern("Intern", 150);
		PresidentialPardonForm form("Arthur Dent");

		form.beSigned(intern);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void testRobotomy()
{
	printTitle("ROBOTOMY TEST");

	try
	{
		Bureaucrat boss("Boss", 1);
		RobotomyRequestForm form("Marvin");

		form.beSigned(boss);

		for (int i = 0; i < 5; i++)
			form.execute(boss);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void testShrubbery()
{
	printTitle("SHRUBBERY TEST");

	try
	{
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm form("garden");

		form.beSigned(boss);
		form.execute(boss);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main(void)
{
	std::srand(std::time(NULL));

	testPresidentialSuccess();
	testUnsignedForm();
	testGradeTooLowExecute();
	testGradeTooLowSign();
	testRobotomy();
	testShrubbery();
	
	return (EXIT_SUCCESS);
}
