/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 10:51:26 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/16 11:05:43 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
	private:
		std::string const	_name;
		size_t				_grade;
	public:
		Bureaucrat();	// default constructor
		Bureaucrat(std::string _name);	// constructor with name only
		Bureaucrat(size_t _grade);	// constructor with grade only
		Bureaucrat(std::string _name, size_t _grade); // constructor with name and grade
		Bureaucrat(Bureaucrat const & src); // copy constructor
		~Bureaucrat(); // destructor

		// overload assignment operator
		Bureaucrat & operator=(Bureaucrat const & src);

		// Getters
		std::string getName() const;
		size_t getGrade() const;

		// Setters
		void setGrade(size_t _grade);

		// Methods
		void incrementGrade();
		void decrementGrade();

		// Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

};

// ostream Overload
std::ostream& operator<<(std::ostream& o, Bureaucrat* a);

#endif