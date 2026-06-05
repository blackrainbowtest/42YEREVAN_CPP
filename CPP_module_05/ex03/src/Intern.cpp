/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 10:36:35 by aramarak          #+#    #+#             */
/*   Updated: 2026/06/05 10:36:45 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "color_palletre.hpp"

Intern::Intern(void)
{
    std::cout << GREEN << "Intern Default Constructor called" << RESET << std::endl;
}

Intern::Intern(const Intern &src)
{
    std::cout << GREEN << "Intern copy constructor called"
		<< RESET << std::endl;
    return (*this);
}

Intern::~Intern(void)
{
    std::cout << GREEN << "Intern destructor called" << RESET << std::endl;
}

Intern &Intern::operator=(const Intern &src)
{
	(void)src;
	return (*this);
}

// static
static AForm *makePresidentialPardonForm(const std::string &target)
{
    return (new PresidentialPardonForm(target));
}

static AForm *makeRobotomyRequestForm(const std::string &target)
{
    return (new RobotomyRequestForm(target));
}

static AForm *makeShrubberyCreationForm(const std::string &target)
{
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(const std::string &form, const std::string &target)
{
    std::cout << RED << "Intern cant create " << form << RESET << std::endl;
    return (NULL);
}