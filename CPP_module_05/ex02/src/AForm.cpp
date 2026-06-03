/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
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

AForm::AForm(void): _name("default"), _is_signed(false), _sign_req_grade(150),
                  _exec_req_grade(150)
{
	std::cout << GREEN << "AForm Default Constructor called" << RESET << std::endl;
}

AForm::AForm(const std::string name, const int sign_req_grade, const int exec_req_grade)
        : _name(name), _is_signed(false), _sign_req_grade(sign_req_grade),
        _exec_req_grade(exec_req_grade)
{
    validateGrade(sign_req_grade);
    validateGrade(exec_req_grade);
    std::cout << GREEN << "AForm constructor with sign and execution grade called" << RESET << std::endl;
}

AForm::AForm(AForm const & src): _name(src._name), _is_signed(src._is_signed),
        _sign_req_grade(src._sign_req_grade), _exec_req_grade(src._exec_req_grade)
{
	std::cout << GREEN << "AForm copy constructor called" << RESET << std::endl;
}

AForm::~AForm()
{
	std::cout << RED << "AForm destructor called" << RESET << std::endl;
}

void AForm::validateGrade(int grade)
{
    if (grade < 1)
		throw AForm::GradeTooHighException();
	if (grade > 150)
		throw AForm::GradeTooLowException();
}

void AForm::validateExecution(Bureaucrat const &executor) const
{
	if (!_is_signed)
		throw FormNotSignedException();

	if (executor.getGrade() > _exec_req_grade)
		throw GradeTooLowException();
}

AForm &AForm::operator=(const AForm &src)
{
    std::cout << GREEN << "AForm assignment operator called" << RESET << std::endl;
	if (this != &src)
		this->_is_signed = src._is_signed;

	return (*this);
}

const std::string&  AForm::getName(void) const
{
    return (this->_name);
}

bool    AForm::getIsSigned(void) const
{
    return (this->_is_signed);
}
int     AForm::getSignGrade(void)const
{
    return (this->_sign_req_grade);
}
int     AForm::getExecGrade(void)const
{
    return (this->_exec_req_grade);
}

void AForm::beSigned(const Bureaucrat &signer)
{
    if (signer.getGrade() > this->_sign_req_grade)
        throw AForm::GradeTooLowException();
    this->_is_signed = true;
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
    return ("Grade too low");
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
    return ("Grade too high");
}

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form not signed");
}

std::ostream & operator<<(std::ostream &os, AForm const & src)
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