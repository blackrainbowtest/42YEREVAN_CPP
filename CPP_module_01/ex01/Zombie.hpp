/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:37:55 by aramarak          #+#    #+#             */
/*   Updated: 2026/04/30 18:02:57 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string _name;
	public:
	// constructor
		Zombie();
	// destructor
		~Zombie();
	// member functions
	void	announce(void)const;
	void	set_name(std::string name);
};

Zombie*	zombieHorde( int N, std::string name );

#endif
