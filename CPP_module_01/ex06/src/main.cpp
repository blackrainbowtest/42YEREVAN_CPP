/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 15:22:41 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/03 14:03:28 by root             ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << MAGENTA << "Usage: " << argv[0] << " <complaint_level>" 
				  << RESET << std::endl;
		std::cerr << "Complaint levels: " << CYAN << "DEBUG, INFO, WARNING, ERROR" 
				  << RESET << std::endl;
		return (EXIT_FAILURE);
	}
	Harl harl;
	harl.complain(argv[1]);
	return (EXIT_SUCCESS);
}