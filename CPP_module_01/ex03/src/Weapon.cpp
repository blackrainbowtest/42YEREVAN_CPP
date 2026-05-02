/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 14:12:14 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/02 15:12:18 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

#define BLACK   "\033[30m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN    "\033[46m"
#define RESET     "\033[0m"

// constructor
	Weapon::Weapon(const std::string &weapon_type)
	{
		this->setType(weapon_type);
	}
// destructor
	Weapon::~Weapon(void)
	{
		std::cout	<< BG_MAGENTA << BLACK << this->getType() 
					<< RESET << " now can be looted by "
					<< MAGENTA << "other players!" << RESET 
					<< std::endl;
	}
// getter
	std::string Weapon::getType(void) const
	{
		return (_type);
	}
// setter
	void Weapon::setType(const std::string &weapon_type)
	{
		_type = weapon_type;
	}