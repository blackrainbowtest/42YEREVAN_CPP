/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:06:51 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/08 20:06:52 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

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

ClapTrap::ClapTrap()
	: _name("user"),
	  _base_attack(0),
	  _base_stamina(10),
	  _base_health(10)
{
	std::cout << CYAN << "ClapTrap" << " " << BG_MAGENTA << BLACK  
			  << "Default constructor" << RESET << " called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& copy)
{
	*this = copy;
	std::cout << CYAN << "ClapTrap" << " " << BG_MAGENTA << BLACK 
			  << "Copy constructor" << RESET << " " << "called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name),
	  _base_attack(0),
	  _base_stamina(10),
	  _base_health(10)
{
	std::cout << CYAN << "ClapTrap" << " " << BG_MAGENTA << BLACK 
			  << "Name constructor" << RESET 
			  << " " << "for " << YELLOW << _name << RESET
			  << " " << "called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << CYAN << "ClapTrap" << " " << BG_RED << YELLOW 
			  << "Destructor" << RESET 
			  << " " << "for " << YELLOW << _name << RESET
			  << " " << "called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src)
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

void	ClapTrap::attack(const std::string& target)
{
	if (this->_base_stamina > 0 && this->_base_health > 0)
	{
		std::cout << CYAN << "ClapTrap" << " " << BG_YELLOW << BLACK 
				  << "Attack" << RESET 
				  << " " << "for " << YELLOW << _name << RESET
				  << " " << "on " << YELLOW << target << RESET
				  << std::endl;
		if (this->_base_stamina > 0)
			this->_base_stamina--;
		else
			this->_base_stamina = 0;
	}
	else
	{
		std::cout << CYAN << "ClapTrap" << " " << BG_RED << BLACK 
				  << "Cannot attack" << RESET 
				  << " " << "for " << YELLOW << _name << RESET
				  << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_base_health > 0)
	{
		std::cout << CYAN << "ClapTrap" << " " << BG_MAGENTA << BLACK 
				  << "Take damage" << RESET 
				  << " " << "for " << YELLOW << _name << RESET
				  << " " << "of " << YELLOW << amount << RESET
				  << std::endl;
		if (amount >= this->_base_health)
			this->_base_health = 0;
		else
			this->_base_health -= amount;
	}
	else
	{
		std::cout << CYAN << "ClapTrap" << " " << BG_RED << BLACK 
				  << "Cannot take damage" << RESET 
				  << " " << "for " << YELLOW << _name << RESET
				  << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_base_stamina > 0 && this->_base_health > 0)
	{
		std::cout << CYAN << "ClapTrap" << " " << BG_CYAN << BLACK 
				  << "Be repaired" << RESET 
				  << " " << "for " << YELLOW << _name << RESET
				  << " " << "of " << YELLOW << amount << RESET
				  << std::endl;
		if (this->_base_health + amount > 10)
			this->_base_health = 10;
		else
			this->_base_health += amount;
		if (this->_base_stamina > 0)
			this->_base_stamina--;
		else
			this->_base_stamina = 0;
	}
	else
	{
		std::cout << CYAN << "ClapTrap" << " " << BG_RED << BLACK 
				  << "Cannot be repaired" << RESET 
				  << " " << "for " << YELLOW << _name << RESET
				  << std::endl;
	}
}