/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:53:53 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/02 12:40:21 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructor
Zombie::Zombie()
{
}

// Destructor
Zombie::~Zombie()
{
	std::cout << "Horde member " << BG_GREEN << _name 
				<< RESET << " has passed away." << std::endl;
}

// name setter
void	Zombie::set_name(std::string name)
{
	this->_name = name;
}

// zombie announce
void	Zombie::announce(void) const
{
	std::cout	<< BG_GREEN << _name
				<< RESET << YELLOW << ":  BraiiiiiiinnnzzzZ..." 
				<< RESET << std::endl;
}
