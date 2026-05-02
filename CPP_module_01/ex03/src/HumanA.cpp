/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 14:12:06 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/02 15:11:12 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN    "\033[46m"
#define RESET     "\033[0m"

// constructor
HumanA::HumanA(const std::string &name, Weapon &weapon)
    	: _name(name), _weapon(weapon)
{
	std::cout << "\n" << BG_CYAN << BLACK << "Combat log: " << RESET
			  << MAGENTA << this->_name << RESET
			  << " enter into the dungeon. "
			  << "User equip "
			  << CYAN << this->_weapon.getType()
			  << RESET << " weapon."
			  << std::endl;
}
// destructor
HumanA::~HumanA(void)
{
	std::cout << RED << this->_name << " died." << RESET << std::endl;
}
// actions
void HumanA::attack(void) const
{
	std::cout << GREEN << this->_name << " attacks"
			<< RESET << " with his "
			<< CYAN << this->_weapon.getType() << RESET
			<< "." << std::endl;
}
