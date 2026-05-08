/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 15:22:41 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/08 20:06:57 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

	// testing 02 (ScavTrap)
	{
		std::cout << CYAN << "Testing 02" << RESET << std::endl;
		ScavTrap b("ScavTrap B");
		b.attack("Target 2");
		b.takeDamage(5);
		b.beRepaired(3);
		b.guardGate();
		std::cout << std::endl;
	}

	// testing 03 (FragTrap)
	{
		std::cout << CYAN << "Testing 03" << RESET << std::endl;
		FragTrap c("FragTrap C");
		c.attack("Target 3");
		c.takeDamage(20);
		c.beRepaired(10);
		c.highFivesGuys();
		std::cout << std::endl;
	}

	// testing 04 (not enought stamina)
	{
		std::cout << CYAN << "Testing 04" << RESET << std::endl;
		ClapTrap d("ClapTrap D");
		for (int i = 0; i < 10; i++)
			d.attack("Target 4");
		d.attack("Target 4");
		std::cout << std::endl;

		ScavTrap e("ScavTrap E");
		for (int i = 0; i < 50; i++)
			e.attack("Target 5");
		e.attack("Target 5");
		std::cout << std::endl;

		FragTrap f("FragTrap F");
		for (int i = 0; i < 100; i++)
			f.attack("Target 6");
		f.attack("Target 6");
		std::cout << std::endl;
	}

	// testing 05 (not enought health)
	{
		std::cout << CYAN << "Testing 05" << RESET << std::endl;
		ClapTrap g("ClapTrap G");
		g.takeDamage(10);
		g.attack("Target 7");
		g.beRepaired(5);
		std::cout << std::endl;

		ScavTrap h("ScavTrap H");
		h.takeDamage(100);
		h.attack("Target 8");
		h.beRepaired(10);
		h.guardGate();
		std::cout << std::endl;

		FragTrap i("FragTrap I");
		i.takeDamage(100);
		i.attack("Target 9");
		i.beRepaired(10);
		i.highFivesGuys();
		std::cout << std::endl;
	}

	// testing 06 (special methods)
	{
		std::cout << CYAN << "Testing 06" << RESET << std::endl;
		ScavTrap j("ScavTrap J");
		j.guardGate();
		j.guardGate();
		std::cout << std::endl;

		FragTrap k("FragTrap K");
		k.highFivesGuys();
		std::cout << std::endl;
	}
	return (EXIT_SUCCESS);
}
