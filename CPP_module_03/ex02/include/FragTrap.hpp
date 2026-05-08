/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:06:42 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/08 20:06:43 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
	// Constructors
		FragTrap();
		FragTrap(const FragTrap& copy);
		FragTrap(std::string name);

	// Destructor
		~FragTrap();
	
	// Overloaded operators
		FragTrap& operator=(const FragTrap& src);
	
	// Subject methods
		void	highFivesGuys(void);
};

#endif // !FRAGTRAP_HPP