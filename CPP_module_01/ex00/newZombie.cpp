/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:54:01 by aramarak          #+#    #+#             */
/*   Updated: 2026/04/30 17:43:12 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* 	newZombie( std::string name )
{
	Zombie *mr_zombie = new Zombie(name);
	mr_zombie->announce();
	return (mr_zombie);
}
