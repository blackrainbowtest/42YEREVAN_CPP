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

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "color_pallete.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << GREEN << "Bureaucrat default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150)
{
	std::cout << GREEN << "Bureaucrat constructor with name only called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(int grade) : _name("Default"), _grade(150)
{
	Bureaucrat::validateGrade(grade);
	this->_grade = grade;
	std::cout << GREEN << "Bureaucrat constructor with grade only called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(150)
{
	Bureaucrat::validateGrade(grade);
	this->_grade = grade;
	std::cout << GREEN << "Bureaucrat constructor with name and grade called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name), _grade(src._grade)
{
	std::cout << GREEN << "Bureaucrat copy constructor called" << RESET << std::endl;
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
		this->_grade = src._grade;
	return *this;
}

// Getters
std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::validateGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

// Methods
void Bureaucrat::incrementGrade()
{
	validateGrade(this->_grade - 1);
	this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	validateGrade(this->_grade + 1);
	this->_grade++;
}

void	signForm(Form &form)
{
	form.beSigned(*this);
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
