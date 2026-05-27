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

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;
		static void			validateGrade(int grade);

	public:
		Bureaucrat();	// default constructor
		Bureaucrat(std::string name);	// constructor with name only
		Bureaucrat(int grade);	// constructor with grade only
		Bureaucrat(std::string name, int grade); // constructor with name and grade
		Bureaucrat(Bureaucrat const &src); // copy constructor
		~Bureaucrat(); // destructor

		// overload assignment operator
		Bureaucrat & operator=(Bureaucrat const &src);

		// Getters
		std::string getName() const;
		int getGrade() const;

		// Methods
		void		incrementGrade();
		void		decrementGrade();

		// Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

};

std::ostream& operator<<(std::ostream& o, Bureaucrat const &a);

#endif