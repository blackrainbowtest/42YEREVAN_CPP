/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 16:14:52 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/07 22:01:52 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ClapTrap_HPP
# define ClapTrap_HPP

#include <string>
#include <iostream>

class ClapTrap
{
	// protected
	protected:
		std::string		_name;
		unsigned int	_base_attack;
		unsigned int	_base_stamina;
		unsigned int	_base_health;
	
	public:
	// Constructors
		ClapTrap();
		ClapTrap(const ClapTrap& copy);
		ClapTrap(std::string name);
	// Destructor
		~ClapTrap();
	// Overloaded operators
		ClapTrap& operator=(const ClapTrap& src);
	// Subject methods
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif // ClapTrap_HPP
