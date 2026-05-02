/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:54:04 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/02 13:24:27 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>

#define BLACK   "\033[30m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN    "\033[46m"
#define RESET     "\033[0m"

int	main()
{
	std::string string = "HI THIS IS BRAIN";	
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "\n" << BG_CYAN << BLACK << "ADDRESSES" << RESET << "\n\n";
	
	std::cout << std::left << std::setfill('.');
	
	std::cout 	<< std::setw(50)
				<< "The memory address of the string variable" 
				<< CYAN << &string << RESET << "\n";
	std::cout 	<< std::setw(50)
				<< "The memory address held by stringPTR" 
				<< CYAN<< stringPTR << RESET<< "\n";
	std::cout 	<< std::setw(50)
				<< "The memory address held by stringREF" 
				<< CYAN<< &stringREF << RESET<< "\n";

	std::cout << "\n" << BG_MAGENTA << BLACK << "VALUE" << RESET << "\n\n";
	
	std::cout 	<< std::setw(50)
				<< "The value of the string variable" 
				<< MAGENTA << string << RESET << "\n";
	std::cout 	<< std::setw(50)
				<< "The value pointed to by stringPTR" 
				<< MAGENTA<< *stringPTR << RESET<< "\n";
	std::cout 	<< std::setw(50)
				<< "The value pointed to by stringREF" 
				<< MAGENTA<< stringREF << RESET<< "\n";
	
	return (0);
}
