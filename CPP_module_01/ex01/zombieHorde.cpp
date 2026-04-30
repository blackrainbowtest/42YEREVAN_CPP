/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 18:03:02 by aramarak          #+#    #+#             */
/*   Updated: 2026/04/30 18:06:30 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N < 1)
	{
		std::cout << "Horde cant contain less than one zombie!" << std::endl;
	}
	// creating horde (allocating N classes)
	Zombie *horde = new Zombie[N];
	if (NULL == horde)
	{
		std::cout << "I couldnt allocate your horde! exiting programm." << std::endl;
		return (NULL);	
	}
}
