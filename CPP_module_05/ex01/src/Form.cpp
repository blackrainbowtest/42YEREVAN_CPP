/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 10:51:26 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/26 01:05:43 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "color_pallete.hpp"

Form::Form(void): _name("default"), _is_signed(false), _sign_req_grade(150),
                  _exec_req_grade(150)
{
	std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form(const std::string name, const int sign_req_grade, const int exec_req_grade)
        : _name(name), _is_signed(false), _sign_req_grade(sign_req_grade),
        _exec_req_grade(exec_req_grade)
{
    validateGrade(sign_req_grade);
    validateGrade(exec_req_grade);
    std::cout << GREEN << "Form constructor with sign and execution grade called" << RESET << std::endl;
}

Form::Form(Form const & src): _name(src._name), _is_signed(src._is_signed),
        _sign_req_grade(src._sign_req_grade), _exec_req_grade(src._exec_req_grade)
{
	std::cout << GREEN << "Form copy constructor called" << RESET << std::endl;
}

Form::~Form()
{
	std::cout << RED << "Form destructor called" << RESET << std::endl;
}

void Form::validateGrade(int grade)
{
    if (grade < 1)
		throw Form::GradeTooHighException();
	if (grade > 150)
		throw Form::GradeTooLowException();
}

Form &Form::operator=(const Form &src)
{
    std::cout << GREEN << "Form assignment operator called" << RESET << std::endl;
	if (this != &src)
		this->_is_signed = src._is_signed;

	return (*this);
}

const std::string&  Form::getName(void) const
{
    return (this->_name);
}

bool    Form::getIsSigned(void) const
{
    return (this->_is_signed);
}
int     Form::getSignGrade(void)const
{
    return (this->_sign_req_grade);
}
int     Form::getExecGrade(void)const
{
    return (this->_exec_req_grade);
}

void Form::beSigned(const Bureaucrat &signer)
{
    if (signer.getSignGrade() > this->_sign_req_grade)
        throw Form::GradeTooLowException();
        this->_is_signed = true;
}

const char *Form::GradeTooLowException::what(void) const throw()
{
    return ("Grade too low");
}

const char *Form::GradeTooHighException::what(void) const throw()
{
    return ("Grade too high");
}

std::ostream & operator<<(std::ostream &os, Form const & src)
{
    os << src.getName()
	   << ", signed: "
	   << (src.getIsSigned() ? "yes" : "no")
	   << ", sign grade: "
	   << src.getSignGrade()
	   << ", exec grade: "
	   << src.getExecGrade();
    return (os);
}