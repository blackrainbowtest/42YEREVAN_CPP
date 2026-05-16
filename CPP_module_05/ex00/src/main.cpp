/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:54:04 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/16 10:50:51 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
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
	printSection("Test");
	
	
	return (EXIT_SUCCESS);
}
