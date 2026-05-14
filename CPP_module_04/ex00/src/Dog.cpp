/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:07:24 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/14 18:06:12 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"


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

Dog::Dog(): Animal()
{
	this->_type = "Dog";
	std::cout << BG_CYAN << BLACK << "[constructor]"
		<< RESET << ": Dog " << MAGENTA
		<< "Default" << RESET << " Constructor called"
		<< std::endl;
}

Dog::Dog(const Dog& copy): Animal(copy)
{
	std::cout << BG_CYAN << BLACK << "[constructor]"
		<< RESET << ": Dog " << MAGENTA
		<< "Copy" << RESET << " Constructor called"
		<< std::endl;
}

Dog::~Dog()
{
	std::cout << BG_MAGENTA << BLACK << "[destructor]"
		<< RESET << ": Dog Destructor called"
		<< std::endl;
}

Dog& Dog::operator=(const Dog& src)
{
	std::cout << BG_YELLOW << BLACK << "[assignation]"
		<< RESET << ": Dog " << CYAN
		<< "Assignation" << RESET << " Operator called"
		<< std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void Dog::makeSound(void)const
{
	std::cout << BG_YELLOW << BLACK << "[makeSound]"
		<< RESET << ": This " << this->getType() << MAGENTA
		<< " barks" << RESET << " loudly."
		<< std::endl;
}
