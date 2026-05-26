/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 09:36:02 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/25 09:36:02 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string		_name;
        bool                    _is_signed;
        const size_t            _sign_req_grade;
        const size_t			_exec_req_grade;
    public:
        Form(); // constructor
        Form(const std::string name); // constructor with name only
        Form(const size_t sign_req_grade, const size_t exec_req_grade); // constructor with grades only
        Form(const std::string name, const size_t sign_req_grade, const size_t exec_req_grade); // constructor with name and grades
        Form(Form const & copy); // copy constructor
        ~Form(); // descructor

    // overload assignment operator
        Form & operator=(Form const & src);

    // Getters

    // Setters

    // Methods

    // Exceptions
    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char *what() const throw();
    }

    class GradeTooHightException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    }
}

// ostream Overload
std::ostream& operator<<(std::ostream& o, Form* a);

#endif