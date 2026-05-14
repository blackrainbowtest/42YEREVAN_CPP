/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:07:22 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/14 18:06:00 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"


#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define BLACK		"\033[30m"
#define RED			"\033[31m"
#define YELLOW		"\033[33m"
#define MAGENTA		"\033[35m"
#define CYAN		"\033[36m"

#define BG_RED		"\033[41m"
#define BG_YELLOW	"\033[43m"
#define BG_MAGENTA	"\033[45m"
#define BG_CYAN		"\033[46m"

#define RESET		"\033[0m"

Cat::Cat(): Animal()
{
	this->_type = "Cat";
	std::cout << BG_CYAN << BLACK << "[constructor]"
		<< RESET << ": Cat " << MAGENTA
		<< "Default" << RESET << " Constructor called"
		<< std::endl;
}

Cat::Cat(const Cat& copy): Animal(copy)
{
	std::cout << BG_CYAN << BLACK << "[constructor]"
		<< RESET << ": Cat " << MAGENTA
		<< "Copy" << RESET << " Constructor called"
		<< std::endl;
}

Cat::~Cat()
{
	std::cout << BG_MAGENTA << BLACK << "[destructor]"
		<< RESET << ": Cat Destructor called"
		<< std::endl;
}

Cat& Cat::operator=(const Cat& src)
{
	std::cout << BG_YELLOW << BLACK << "[assignation]"
		<< RESET << ": Cat " << CYAN
		<< "Assignation" << RESET << " Operator called"
		<< std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void Cat::makeSound(void)const
{
	std::cout << BG_YELLOW << BLACK << "[makeSound]"
		<< RESET << ": This " << this->getType() << MAGENTA
		<< " meows" << RESET << " loudly."
		<< std::endl;
}
