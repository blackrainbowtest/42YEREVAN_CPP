/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:07:29 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/08 20:07:30 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"


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

WrongCat::WrongCat(): WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << BG_CYAN << BLACK << "[constructor]"
		<< RESET << ": WrongCat " << MAGENTA
		<< "Default" << RESET << " Constructor called"
		<< std::endl;
}

WrongCat::WrongCat(const WrongCat& copy): WrongAnimal(copy)
{
	*this = copy;
	std::cout << BG_CYAN << BLACK << "[constructor]"
		<< RESET << ": WrongCat " << MAGENTA
		<< "Copy" << RESET << " Constructor called"
		<< std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << BG_MAGENTA << BLACK << "[destructor]"
		<< RESET << ": WrongCat Destructor called"
		<< std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& src)
{
	std::cout << BG_YELLOW << BLACK << "[assignation]"
		<< RESET << ": WrongCat " << CYAN
		<< "Assignation" << RESET << " Operator called"
		<< std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void WrongCat::makeSound(void)const
{
	std::cout << BG_YELLOW << BLACK << "[makeSound]"
		<< RESET << ": This " << this->getType() << MAGENTA
		<< " wrong sound" << RESET << " loudly."
		<< std::endl;
}