/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:06:53 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/08 20:06:54 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

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

FragTrap::FragTrap()
	: ClapTrap()
{
	this->_base_health = 100;
	this->_base_stamina = 100;
	this->_base_attack = 30;
	std::cout << CYAN << "FragTrap" << " " << BG_MAGENTA << BLACK  
			  << "Default constructor" << RESET << " called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy)
	: ClapTrap(copy)
{
	std::cout << CYAN << "FragTrap" << " " << BG_MAGENTA << BLACK  
			  << "Copy constructor" << RESET << " called" << std::endl;
}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name)
{
	this->_base_health = 100;
	this->_base_stamina = 100;
	this->_base_attack = 30;
	std::cout << CYAN << "FragTrap" << " " << BG_MAGENTA << BLACK  
			  << "Name constructor" << RESET 
			  << " " << "for " << YELLOW << _name << RESET
			  << " " << "called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << CYAN << "FragTrap" << " " << BG_RED << YELLOW 
			  << "Destructor" << RESET 
			  << " " << "for " << YELLOW << _name << RESET
			  << " " << "called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& src)
{
	std::cout << "Assignation" 
			  << " " << CYAN << "operator" << RESET 
			  << " " << "called" << std::endl;
	this->_name = src._name;
	this->_base_attack = src._base_attack;
	this->_base_health = src._base_health;
	this->_base_stamina = src._base_stamina;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << CYAN << "FragTrap" << " " << BG_YELLOW << BLACK 
			  << "High Fives Guys" << RESET 
			  << " " << "for " << YELLOW << _name << RESET
			  << std::endl;
}

