/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:07:19 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/08 23:57:22 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"


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

Animal::Animal(): _type("default")
{
	std::cout << BG_CYAN << BLACK << "[constructor]"
		<< RESET << ": Animal " << MAGENTA
		<< "Default" << RESET << " Constructor called"
		<< std::endl;
}

Animal::Animal(const Animal& copy): _type(copy._type)
{
	*this = copy;
	std::cout << BG_CYAN << BLACK << "[constructor]"
		<< RESET << ": Animal " << MAGENTA
		<< "Copy" << RESET << " Constructor called"
		<< std::endl;
}

Animal::~Animal()
{
	std::cout << BG_MAGENTA << BLACK << "[destructor]"
		<< RESET << ": Animal Destructor called"
		<< std::endl;
}

Animal& Animal::operator=(const Animal& src)
{
	std::cout << BG_YELLOW << BLACK << "[assignation]"
		<< RESET << ": Animal " << CYAN
		<< "Assignation" << RESET << " Operator called"
		<< std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void Animal::makeSound(void)const
{
	std::cout << BG_YELLOW << BLACK << "[makeSound]"
		<< RESET << ": This animal " << MAGENTA
		<< "doesn't" << RESET << " have any sound."
		<< std::endl;
}

std::string Animal::getType(void)const
{
	return (this->_type);
}
