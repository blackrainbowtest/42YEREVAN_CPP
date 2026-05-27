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

class Bureaucrat;

class Form
{
    private:
        const std::string		_name;
        bool                    _is_signed;
        const int               _sign_req_grade;
        const int			    _exec_req_grade;
    public:
        Form(); // constructor
        Form(const std::string name, const int sign_req_grade, const int exec_req_grade); // constructor with name and grades
        Form(Form const & copy); // copy constructor
        ~Form(); // descructor

    // overload assignment operator
        Form & operator=(Form const & src);

    // Getters
        const std::string&  getName(void) const;
        bool                getIsSigned(void) const;
        int                 getSignGrade(void)const;
        int                 getExecGrade(void)const;
    // Setters

    // Methods
        void beSigned(const Bureaucrat &signer);

    // Exceptions
    class GradeTooLowException : public std::exception
    {
        public:
            const char *what() const throw();
    };

    class GradeTooHighException : public std::exception
    {
        public:
            const char* what() const throw();
    };
};

// ostream Overload
std::ostream& operator<<(std::ostream& o, Form const & a);

#endif