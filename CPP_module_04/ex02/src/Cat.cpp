/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 20:07:22 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/09 00:08:45 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
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

Cat::Cat(): Animal()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	if (this->_brain == NULL)
	{
		std::cerr << RED << "Error: " << RESET
			<< "Failed to allocate memory for Cat's Brain."
			<< std::endl;
		exit(EXIT_FAILURE);
	}
	std::cout << BG_CYAN << BLACK << "[constructor]"
		<< RESET << ": Cat " << MAGENTA
		<< "Default" << RESET << " Constructor called"
		<< std::endl;
}

Cat::Cat(const Cat& copy): Animal(copy)
{
	this->_brain = new Brain(*copy._brain);
    this->_type = copy._type;
	std::cout << BG_CYAN << BLACK << "[constructor]"
		<< RESET << ": Cat " << MAGENTA
		<< "Copy" << RESET << " Constructor called"
		<< std::endl;
}

Cat::~Cat()
{
	if (this->_brain)
		delete this->_brain;
	std::cout << BG_MAGENTA << BLACK << "[destructor]"
		<< RESET << ": Cat Destructor called"
		<< std::endl;
}

Cat& Cat::operator=(const Cat& src)
{
	std::cout << BG_YELLOW << BLACK << "[assignation]"
		<< RESET << ": Cat " << CYAN
		<< "Assignation" << RESET << " Operator called"
		<< std::endl;
	if (this != &src)
	{
		Animal::operator=(src);		
		Brain* newBrain = new Brain(*src._brain);
		if (newBrain == NULL)
		{
			std::cerr << RED << "Error: " << RESET
				<< "Failed to allocate memory for Cat's Brain during assignment."
				<< std::endl;
			exit(EXIT_FAILURE);
		}
		if (this->_brain)
			delete this->_brain;
		this->_brain = newBrain;
	}

	return (*this);
}

void Cat::makeSound(void)const
{
	std::cout << BG_YELLOW << BLACK << "[makeSound]"
		<< RESET << ": This " << this->getType() << MAGENTA
		<< " meows" << RESET << " loudly."
		<< std::endl;
}

void Cat::getIdeas(void) const
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

void Cat::setIdea(size_t index, const std::string& idea)
{
	this->_brain->setIdea(index, idea);
}
