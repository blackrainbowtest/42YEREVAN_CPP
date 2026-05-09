/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:07:07 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/09 00:09:20 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
	private:
		std::string _ideas[100];
	public:
	// Constructor
		Brain();
		Brain(const Brain& copy);
	// Destructor
		virtual ~Brain();
	// Overloaded operator
		Brain &operator=(const Brain& src);
	
	// getter
		const std::string getIdea(int index) const;
		const std::string *getIdeaAddress(int index) const;
	// setter
		void setIdea(size_t index, const std::string& idea);
}

#endif // !BRAIN_HPP