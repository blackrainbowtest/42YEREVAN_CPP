/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 16:37:55 by aramarak          #+#    #+#             */
/*   Updated: 2026/04/30 17:37:47 by aramarak         ###   ########.fr       */
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
		Zombie(std::string name);
	// destructor
		~Zombie();
	// member functions
	void	announce(void)const;
	void	set_name(std::string name);
};

void	randomChump(std::string name);
Zombie	*newZombie( std::string name );

#endif
