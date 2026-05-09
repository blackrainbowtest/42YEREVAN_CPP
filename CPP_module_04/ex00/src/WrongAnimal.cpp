/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:07:31 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/08 20:07:32 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"


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

WrongAnimal::WrongAnimal(): _type("WrongAnimal")
{
	std::cout << BG_CYAN << BLACK << "[constructor]"
		<< RESET << ": WrongAnimal " << MAGENTA
		<< "Default" << RESET << " Constructor called"
		<< std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy): Animal(copy)
{
	*this = copy;
	std::cout << BG_CYAN << BLACK << "[constructor]"
		<< RESET << ": WrongAnimal " << MAGENTA
		<< "Copy" << RESET << " Constructor called"
		<< std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << BG_MAGENTA << BLACK << "[destructor]"
		<< RESET << ": WrongAnimal Destructor called"
		<< std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src)
{
	std::cout << BG_YELLOW << BLACK << "[assignation]"
		<< RESET << ": WrongAnimal " << CYAN
		<< "Assignation" << RESET << " Operator called"
		<< std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void WrongAnimal::makeSound(void)const
{
	std::cout << BG_YELLOW << BLACK << "[makeSound]"
		<< RESET << ": This wrong animal " << MAGENTA
		<< "doesn't" << RESET << " have any sound."
		<< std::endl;
}

std::string WrongAnimal::getType(void)const
{
	return (this->_type);
}
