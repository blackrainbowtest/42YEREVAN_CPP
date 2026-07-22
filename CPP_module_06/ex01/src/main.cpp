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
#include "Serializer.hpp"

#define EXIT_SUCCESS 0
// #define EXIT_FAILURE 1

// static void	printDivider(void)
// {
// 	std::cout << std::endl;
// 	std::cout << "-------------------------------------------------------" << std::endl;
// 	std::cout << std::endl;
// }

// static void	printSection(const std::string& title)
// {
// 	printDivider();
// 	std::cout << BLUE << title << RESET << std::endl;
// 	printDivider();
// }

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
		return (EXIT_FAILURE);
	}
	std::string input = argv[1];

	try
	{
		ScalarConverter::convert(input);
	}
	catch (const std::exception &error)
	{
		std::cerr << error.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
