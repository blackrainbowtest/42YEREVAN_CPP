/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 15:22:41 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/06 19:57:14 by aramarak         ###   ########.fr       */
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
	ClapTrap cl;
	std::cout << "test" << std::endl;
	
	return (EXIT_SUCCESS);
}
