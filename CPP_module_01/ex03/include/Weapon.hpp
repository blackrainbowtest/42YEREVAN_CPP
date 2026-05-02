/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 14:12:01 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/02 14:49:34 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class Weapon
{
	private:
		std::string _type;
	public:
		// Constructor accepts const reference so temporaries bind
		Weapon(const std::string &weapon_type);
		// Destructor
		~Weapon(void);
		// getter
		std::string getType(void) const;
		// setter
		void setType(const std::string &weapon_type);
};

#endif
