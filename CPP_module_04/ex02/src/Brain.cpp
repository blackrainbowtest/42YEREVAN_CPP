/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:07:19 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/14 18:18:00 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Brain.hpp"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define BLACK		"\033[30m"
#define RED			"\033[31m"
#define YELLOW		"\033[33m"
#define MAGENTA		"\033[35m"
#define CYAN		"\033[36m"

#define BG_RED		"\033[41m"
#define BG_YELLOW	"\033[43m"
#define BG_MAGENTA	"\033[45m"
#define BG_CYAN		"\033[46m"

#define RESET		"\033[0m"

Brain::Brain()
{
	std::cout << BG_CYAN << BLACK << "[constructor]"
		<< RESET << ": Brain " << MAGENTA
		<< "Default" << RESET << " Constructor called"
		<< std::endl;
}

Brain::Brain(const Brain& copy)
{
	for (size_t i = 0; i < 100; i++)
		this->_ideas[i] = copy._ideas[i];
	std::cout << BG_CYAN << BLACK << "[constructor]"
		<< RESET << ": Brain " << MAGENTA
		<< "Copy" << RESET << " Constructor called"
		<< std::endl;
}

Brain::~Brain()
{
	std::cout << BG_MAGENTA << BLACK << "[destructor]"
		<< RESET << ": Brain Destructor called"
		<< std::endl;
}

Brain& Brain::operator=(const Brain& src)
{
	std::cout << BG_YELLOW << BLACK << "[assignation]"
		<< RESET << ": Brain " << CYAN
		<< "Assignation" << RESET << " Operator called"
		<< std::endl;
	if (this != &src)
	{
		for (size_t i = 0; i < 100; i++)
		{
			if (src._ideas[i].empty())
				this->_ideas[i].clear();
			else
				this->_ideas[i].assign(src._ideas[i]);
		}
	}
	return (*this);
}

const std::string Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
	{
		std::cerr << RED << "Error: Index out of bounds" << RESET << std::endl;
		return ("");
	}
	return (this->_ideas[index]);
}

const std::string *Brain::getIdeaAddress(int index) const
{
	if (index < 0 || index >= 100)
	{
		std::cerr << RED << "Error: Index out of bounds" << RESET << std::endl;
		return (NULL);
	}
	return (&(this->_ideas[index]));
}

void Brain::setIdea(size_t index, const std::string& idea)
{
	if (index >= 100)
	{
		std::cerr << RED << "Error: Index out of bounds" << RESET << std::endl;
		return;
	}
	this->_ideas[index] = idea;
}