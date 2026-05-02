/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:54:04 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/02 12:33:53 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	*horde;
	int		hordeMembersCount = 10;

	horde = zombieHorde(hordeMembersCount, "mr. Zombie");
	if (NULL == horde)
		return (1);
	for (int xi = 0; xi < hordeMembersCount; xi++)
	{
		horde[xi].announce();
	}
	delete[] horde;
	// tests
	horde = zombieHorde(-1, "horde_member");
	return (0);
}
