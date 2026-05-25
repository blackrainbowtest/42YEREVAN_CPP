/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 10:51:26 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/26 01:05:43 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "color_pallete.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << GREEN << "Bureaucrat default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string _name) : _name(_name), _grade(150)
{
	std::cout << GREEN << "Bureaucrat constructor with name only called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(size_t _grade) : _name("Default"), _grade(_grade)
{
	std::cout << GREEN << "Bureaucrat constructor with grade only called" << RESET << std::endl;
	this->setGrade(_grade);
}

Bureaucrat::Bureaucrat(std::string _name, size_t _grade) : _name(_name), _grade(_grade)
{
	std::cout << GREEN << "Bureaucrat constructor with name and grade called" << RESET << std::endl;
	this->setGrade(_grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name), _grade(src._grade)
{
	std::cout << GREEN << "Bureaucrat copy constructor called" << RESET << std::endl;
	this->setGrade(src._grade);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "Bureaucrat destructor called" << RESET << std::endl;
}

// Overload assignment operator
Bureaucrat & Bureaucrat::operator=(Bureaucrat const & src)
{
	std::cout << GREEN << "Bureaucrat assignment operator called" << RESET << std::endl;
	if (this != &src)
	{
		this->setGrade(src._grade);
	}
	return *this;
}

// Getters
std::string Bureaucrat::getName() const
{
	return this->_name;
}

size_t Bureaucrat::getGrade() const
{
	return this->_grade;
}

// Setters
void Bureaucrat::setGrade(size_t _grade)
{
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = _grade;
}

// Methods
void Bureaucrat::incrementGrade()
{
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

// Exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

// Overload insertion operator
std::ostream & operator<<(std::ostream & os, Bureaucrat const & src)
{
	os << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
	return os;
}
