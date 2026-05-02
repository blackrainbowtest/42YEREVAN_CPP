/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 14:11:45 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/02 14:51:21 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanB
{
	private:
		std::string	_name;
		Weapon		*_weapon;
		bool		_is_armed;
	public:
		// constructor
		HumanB(const std::string &name);
		// destructor
		~HumanB(void);
		// actions
		void attack() const;
		void setWeapon(Weapon &weapon);
};

#endif
