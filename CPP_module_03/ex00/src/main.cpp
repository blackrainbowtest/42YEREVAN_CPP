/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 15:22:41 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/07 01:01:38 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

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
	// testing 01
	{
		std::cout << CYAN << "Testing 01" << RESET << std::endl;
		ClapTrap a("ClapTrap A");
		a.attack("Target 1");
		a.takeDamage(3);
		a.beRepaired(2);
		std::cout << std::endl;
	}
	// testing 02
	{
		std::cout << CYAN << "Testing 02" << RESET << std::endl;
		ClapTrap b("ClapTrap B");
		b.attack("Target 2");
		b.takeDamage(5);
		b.beRepaired(3);
		std::cout << std::endl;
	}
	// testing 03
	{
		std::cout << CYAN << "Testing 03" << RESET << std::endl;
		ClapTrap c("ClapTrap C");
		c.attack("Target 3");
		c.takeDamage(12);
		c.beRepaired(5);
		std::cout << std::endl;
	}
	
	return (EXIT_SUCCESS);
}
