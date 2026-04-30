/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:54:04 by aramarak          #+#    #+#             */
/*   Updated: 2026/04/30 17:43:56 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie *mr_zombie = new Zombie("_mr.zombie.1");
	randomChump("_mr.zombie.2");
	delete mr_zombie;
	return (0);
}
