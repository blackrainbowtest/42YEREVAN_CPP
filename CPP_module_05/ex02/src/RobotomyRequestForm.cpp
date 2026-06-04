/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 10:44:15 by aramarak          #+#    #+#             */
/*   Updated: 2026/06/04 10:44:15 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_palletre.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void)
    : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
    std::cout << GREEN << "RobotomyRequestForm Default Constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << GREEN << "RobotomyRequestForm Constructor for "
        << YELLOW << this->getTarget() << GREEN << " called" 
        << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
    : AForm(src), _target(src.getTarget())
{
    std::cout << GREEN << "RobotomyRequestForm copy constructor called"
		<< RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED << "RobotomyRequestForm destructor called"
		<< RESET << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	validateExecution(executor);

    std::cout << "* DRRRRRRRRRRRRRR *" << std::endl;

	if (std::rand() % 2)
	{
		std::cout << this->_target
			<< " has been robotomized successfully."
			<< std::endl;
	}
	else
	{
		std::cout << "Robotomy failed on "
			<< this->_target
			<< "."
			<< std::endl;
	}
}

const std::string &RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &src)
{
	os << src.getName()
		<< " target: "
		<< src.getTarget();
	return (os);
}