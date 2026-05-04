/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:53:53 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/04 16:24:04 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructor
Zombie::Zombie(std::string name): _name(name)
{
	std::cout << "Mr. " << _name << " now zombie!" << std::endl;
}

// Destructor
Zombie::~Zombie()
{
	std::cout << "Zombie " << _name << " has passed away." << std::endl;
}

// name setter
void	Zombie::set_name(std::string name)
{
	this->_name = name;
}

// zombie announce
void	Zombie::announce(void) const
{
	std::cout << _name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}
