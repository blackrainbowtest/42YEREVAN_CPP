/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 14:12:09 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/02 15:44:10 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN    "\033[46m"
#define RESET     "\033[0m"

// constructor
HumanB::HumanB(const std::string &name): _name(name), _weapon(NULL), _is_armed(false)
{
	std::cout << "\n" << BG_CYAN << BLACK << "Combat log: " << RESET
			  << MAGENTA << this->_name << RESET
			  << " enter into the dungeon. "
			  << std::endl;
}
// destructor
HumanB::~HumanB(void)
{
	std::cout << RED << this->_name << " died." << RESET << std::endl;
}
// actions
void	HumanB::attack() const
{
	if (this->_is_armed && this->_weapon)
	{
		std::cout << GREEN << this->_name << " attacks"
				  << RESET << " with his "
				  << CYAN << this->_weapon->getType() << RESET
				  << "." << std::endl;
	}
    else
    {
        std::cout << GREEN << this->_name << " attacks"
			<< RESET << " with his "
			<< CYAN << "fists" << RESET
			<< "." << std::endl;
    }
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	this->_is_armed = true;
	std::cout << MAGENTA << this->_name << RESET 
			  << " looted a " 
			  << CYAN << this->_weapon->getType() 
			  << RESET << std::endl;
}
