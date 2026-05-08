/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:06:28 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/08 20:06:29 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"

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

// _baseHealth 100, _baseStamina 50, _baseAttack 20
ScavTrap::ScavTrap()
	: ClapTrap(),
	  _guard_mode(false)
{
	this->_base_health = 100;
	this->_base_stamina = 50;
	this->_base_attack = 20;
	std::cout << CYAN << "ScavTrap" << " " << BG_MAGENTA << BLACK  
			  << "Default constructor" << RESET << " called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy)
	: ClapTrap(copy)
{
	this->_guard_mode = copy._guard_mode;
	std::cout << CYAN << "ScavTrap" << " " << BG_MAGENTA << BLACK  
			  << "Copy constructor" << RESET << " called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name),
	  _guard_mode(false)
{
	this->_base_health = 100;
	this->_base_stamina = 50;
	this->_base_attack = 20;
	std::cout << CYAN << "ScavTrap" << " " << BG_MAGENTA << BLACK  
			  << "Name constructor" << RESET 
			  << " " << "for " << YELLOW << _name << RESET
			  << " " << "called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << CYAN << "ScavTrap" << " " << BG_RED << YELLOW 
			  << "Destructor" << RESET 
			  << " " << "for " << YELLOW << _name << RESET
			  << " " << "called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src)
{
	std::cout << "Assignation" 
			  << " " << CYAN << "operator" << RESET 
			  << " " << "called" << std::endl;
	this->_name = src._name;
	this->_base_attack = src._base_attack;
	this->_base_stamina = src._base_stamina;
	this->_base_health = src._base_health;
	this->_guard_mode = src._guard_mode;
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_base_stamina > 0 && this->_base_health > 0)
	{
		std::cout << CYAN << "ScavTrap" << " " << BG_YELLOW << BLACK 
				  << "Attack" << RESET 
				  << " " << "for " << YELLOW << _name << RESET
				  << " " << "attacks " << YELLOW << target << RESET
				  << ", causing " << YELLOW << _base_attack 
				  << RESET << " points of damage!" << std::endl;
		if (this->_base_stamina > 0)
			this->_base_stamina--;
		else
			this->_base_stamina = 0;
	}
	else if (this->_base_health <= 0)
	{
		std::cout << CYAN << "ScavTrap" << " " << BG_RED << BLACK 
				  << "Attack" << RESET 
				  << " " << "for " << YELLOW << _name << RESET
				  << " " << "is too weak to attack, it is dead!" << std::endl;
	}
	else
	{
		std::cout << CYAN << "ScavTrap" << " " << BG_RED << BLACK 
				  << "Attack" << RESET 
				  << " " << "for " << YELLOW << _name << RESET
				  << " " << "is too tired to attack!" << std::endl;
	}
}

void	ScavTrap::guardGate(void)
{
	if (this->_guard_mode)
	{
		std::cout << CYAN << "ScavTrap" << " " << BG_YELLOW << BLACK 
				  << "Guard Gate" << RESET 
				  << " " << "for " << YELLOW << _name << RESET
				  << " " << "is already in Gate keeper mode!" << std::endl;
	}
	else
	{
		this->_guard_mode = true;
		std::cout << CYAN << "ScavTrap" << " " << BG_YELLOW << BLACK 
				  << "Guard Gate" << RESET 
				  << " " << "for " << YELLOW << _name << RESET
				  << " " << "has entered in Gate keeper mode!" << std::endl;
	}
}
