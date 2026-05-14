/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:07:24 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/14 18:16:30 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

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

Dog::Dog(): Animal()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	if (this->_brain == NULL)
	{
		std::cerr << RED << "Error: " << RESET
			<< "Failed to allocate memory for Dog's Brain."
			<< std::endl;
		exit(EXIT_FAILURE);
	}
	std::cout << BG_CYAN << BLACK << "[constructor]"
		<< RESET << ": Dog " << MAGENTA
		<< "Default" << RESET << " Constructor called"
		<< std::endl;
}

Dog::Dog(const Dog& copy): Animal(copy)
{

	this->_brain = new Brain(*copy._brain);
	std::cout << BG_CYAN << BLACK << "[constructor]"
		<< RESET << ": Dog " << MAGENTA
		<< "Copy" << RESET << " Constructor called"
		<< std::endl;
}

Dog::~Dog()
{
	if (this->_brain)
		delete this->_brain;
	std::cout << BG_MAGENTA << BLACK << "[destructor]"
		<< RESET << ": Dog Destructor called"
		<< std::endl;
}

Dog& Dog::operator=(const Dog& src)
{
	std::cout << BG_YELLOW << BLACK << "[assignation]"
		<< RESET << ": Dog " << CYAN
		<< "Assignation" << RESET << " Operator called"
		<< std::endl;
	if (this != &src)
	{
		Animal::operator=(src);		
		Brain* newBrain = new Brain(*src._brain);
		if (newBrain == NULL)
		{
			std::cerr << RED << "Error: " << RESET
				<< "Failed to allocate memory for Dog's Brain during assignment."
				<< std::endl;
			exit(EXIT_FAILURE);
		}
		if (this->_brain)
			delete this->_brain;
		this->_brain = newBrain;
	}

	return (*this);
}

void Dog::makeSound(void)const
{
	std::cout << BG_YELLOW << BLACK << "[makeSound]"
		<< RESET << ": This " << this->getType() << MAGENTA
		<< " barks" << RESET << " loudly."
		<< std::endl;
}

void Dog::getIdeas(void) const
{
	std::cout << BG_YELLOW << BLACK << "[getIdeas]"
		<< RESET << ": " << this->getType() << MAGENTA
		<< " has the following ideas:" << RESET
		<< std::endl;
	for (size_t i = 0; i < 100; i++)
	{
		const std::string& idea = this->_brain->getIdea(i);
		if (!idea.empty())
			std::cout << "  [" << i << "] " << idea << std::endl;
	}
}

void Dog::setIdea(size_t index, const std::string& idea)
{
	this->_brain->setIdea(index, idea);
}