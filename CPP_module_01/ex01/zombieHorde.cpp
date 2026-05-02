/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 18:03:02 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/02 12:38:25 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N < 1)
	{
		std::cout << BOLD << RED << "Horde cant contain less than one zombie!" << RESET << std::endl;
		return (NULL);
	}
	// creating horde (allocating N classes)
	Zombie *horde = new Zombie[N];
	if (NULL == horde)
	{
		std::cout << BLUE << "I couldnt allocate your horde! exiting programm." << RESET << std::endl;
		return (NULL);	
	}
	for (int xi = 0; xi < N; xi++)
	{
		horde[xi].set_name(name);
	}
	return (horde);
}
