/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 10:51:26 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/26 01:05:43 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_palletre.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
    : AForm("PresidentialPardonForm", 25, 5), _target("default")
{
    std::cout << GREEN << "PresidentialPardonForm Default Constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << GREEN << "PresidentialPardonForm Constructor for "
        << YELLOW << this->getTarget() << GREEN << " called" 
        << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
    : AForm(src), _target(src.getTarget())
{
    std::cout << GREEN << "PresidentialPardonForm copy constructor called"
		<< RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED << "PresidentialPardonForm destructor called"
		<< RESET << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	validateExecution(executor);

	std::cout << this->_target
		<< " has been pardoned by Zaphod Beeblebrox."
		<< std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src._target;
	}
	return (*this);
}

const std::string &PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

std::ostream &operator<<(std::ostream &os,
	const PresidentialPardonForm &src)
{
	os << src.getName();
	return (os);
}
