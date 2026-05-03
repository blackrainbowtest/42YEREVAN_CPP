/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 15:22:41 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/03 13:28:50 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Harl.hpp"

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
	Harl harl;
	std::string input;
	
	std::cout << CYAN << "Welcome to Harl's Complaint System!" << RESET << std::endl;
	std::cout << "Here how Harl complains:" << std::endl;
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	
	std::cout << MAGENTA << "Enter a complaint level (DEBUG, INFO, WARNING, ERROR): " 
			  << RESET << std::endl;
	
	while (true)
	{
		std::cout << "> ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl << MAGENTA << "Exiting Harl's Complaint System. Goodbye!" 
					  << RESET << std::endl;
			break;
		}
		harl.complain(input);
		std::cout << std::flush;
	}
	return (EXIT_SUCCESS);
}