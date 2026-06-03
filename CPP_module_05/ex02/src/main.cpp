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

int	main(void)
{
	printSection("PRESIDENTIAL PARDON SUCCESS");

	try
	{
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Arthur Dent");

		pardon.beSigned(president);

		std::cout << pardon << std::endl;

		pardon.execute(president);
	}
	catch (const std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	
	return (EXIT_SUCCESS);
}
