/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 10:44:05 by aramarak          #+#    #+#             */
/*   Updated: 2026/06/04 10:44:05 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_palletre.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : AForm("ShrubberyCreationForm", 72, 45), _target("default")
{
    std::cout << GREEN << "ShrubberyCreationForm Default Constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 72, 45), _target(target)
{
    std::cout << GREEN << "ShrubberyCreationForm Constructor for "
        << YELLOW << this->getTarget() << GREEN << " called" 
        << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
    : AForm(src), _target(src.getTarget())
{
    std::cout << GREEN << "ShrubberyCreationForm copy constructor called"
		<< RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << "ShrubberyCreationForm destructor called"
		<< RESET << std::endl;
}